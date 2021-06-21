//
// Created by Christian Ledgard on 18/06/21.
//

#ifndef LAB5_GRAMMAR_H
#define LAB5_GRAMMAR_H
#define EXTRAER "extraer"
#define EXPLORAR "explorar"

#include <map>
#include <vector>
#include <stack>
#include <queue>
#include "Element.h"
#include "printUtils.h"
#include "AnalizadorLexico/LexAnalyzer.h"

class Grammar{
private:

    std::map<NonTerminal*, vector<vector<Element*>>> grammar;
    NonTerminal* startingNT;
    map<NonTerminal*, map<string, vector<Element*>>> ll1;
    set<string> terminals;



    void calculateFirst(){
        bool changes = false;
        for (auto &nt : this->grammar){
            for (vector<Element*>& rule : nt.second){
                bool addEpsilon = true;
                for (Element*& element : rule){
                    NonTerminal* a = nt.first;
                    changes = changes || a->addToFirst(element->getFirstSet());
                    if(!element->isEpsilonInFirst()){addEpsilon = false; break;}
                }
                if (addEpsilon) {
                    NonTerminal* a = nt.first;
                    changes = changes || a->addToFirst(set<string>{EPSILON});
                }
            }
        }
        if (changes) calculateFirst();
    }

    void caclulateNext(){
        startingNT->addToNext(set<string>{DOLLAR});
        bool changes = false;
        for (auto &nt : this->grammar){
            for (vector<Element*>& rule : nt.second){
                for (int i = 0; i < rule.size(); i++){
                    bool hasEpsilon = true;
                    for (int j = i+1; j < rule.size(); j++){
                        changes = changes || rule[i]->addToNext(rule[j]->getFirstSet());
                        if (!rule[j]->isEpsilonInFirst()) hasEpsilon = false;
                        if(rule[j]->isTerminal()) break;
                    }
                    if (hasEpsilon) {
                        NonTerminal* a = nt.first;
                        changes = changes || rule[i]->addToNext(a->getNext());
                    }
                }

            }
        }
        if (changes) caclulateNext();
    }
    
    
    
    void calculateLL1(){
        for (auto &nt: this->grammar) {
            for (auto &rule : nt.second) {
                for (auto &token : rule[0]->getFirstSet()){
                    if(ll1[nt.first].find(token) == ll1[nt.first].end()){
                            ll1[nt.first][token] = rule;
                        if (rule[0]->isEpsilonInFirst()){
                            for (auto &token2 : nt.first->getNext()){
                                if(ll1[nt.first].find(token2) == ll1[nt.first].end())
                                    ll1[nt.first][token2] = rule;
                                else cerr<< "La gramática ingresada no es LL1." << endl;
                            }
                        }
                    } else cerr<< "La gramática ingresada no es LL1." << endl;
                }
            }
        }      
        for (auto &nt : this->grammar){
            for (auto &term : terminals) {
                    if (ll1[nt.first].find(term) == ll1[nt.first].end()) {
                        if (nt.first->getNext().count(term)) {
                            ll1[nt.first][term] = vector<Element *>{new Terminal{EXTRAER}};
                        } else {
                            ll1[nt.first][term] = vector<Element *>{new Terminal{EXPLORAR}};
                        }
                }
            }
            if (ll1[nt.first].find(DOLLAR) == ll1[nt.first].end())
                ll1[nt.first][DOLLAR] = vector<Element *>{new Terminal{EXTRAER}};
        }
    }


    void calculateAllTerminals(){
        for (auto &nt : this->grammar)
            for (auto &rule: nt.second)
                for(auto &elem : rule)
                    if(elem->isTerminal() && elem->getKey() != EPSILON)
                        terminals.insert(elem->getKey());
    }
    
    
public:
    
    Grammar(const map<NonTerminal*, vector<vector<Element*>>> &grammar, NonTerminal* startingNT, bool isLL1 = false) : grammar(grammar), startingNT(startingNT){
        calculateFirst();
        caclulateNext();
        calculateAllTerminals();
        if(isLL1) calculateLL1();
    };




    void printLL1(){
        printElem(separator, nameWidth);
        for(auto &term : terminals){
            printElem(term, nameWidth);
        }
        printElem(DOLLAR, nameWidth);
        cout << endl;
        
        for(auto &nt : ll1){
            printElem(nt.first->getKey(), nameWidth);
            for (auto &term : terminals) {
                string elem2p;
                elem2p += nt.first->getKey();
                elem2p += " -> ";
                for(auto &elem : ll1[nt.first][term]){
                    elem2p += elem->getKey();
                    elem2p += " ";
                }
                printElem(elem2p, nameWidth);
                elem2p.clear();
            }
            string elem2p;
            elem2p += nt.first->getKey();
            elem2p += " -> ";
            for(auto &elem : ll1[nt.first][DOLLAR]){
                elem2p += elem->getKey();
                elem2p += " ";
            }
            printElem(elem2p, nameWidth);
            elem2p.clear();
            cout << endl;
        }
        
    }
    
    

    map<NonTerminal*, set<string>> getFirsts(){
        map<NonTerminal*, set<string>> result;
        for (auto &nt : this->grammar){
            result[nt.first] = nt.first->getFirst();
        }
        return result;
    }

    map<NonTerminal*, set<string>> getNexts(){
        map<NonTerminal*, set<string>> result;
        for (auto &nt : this->grammar){
            result[nt.first] = nt.first->getNext();
        }
        return result;
    }
    

    
    void printFirst(){
        for (auto &nt : this->grammar){
            cout << "Primero("<<nt.first->getKey() << ")={";
            for (auto &elem : nt.first->getFirst()){
                cout << elem << ", ";
            }
            cout << "}\n";
        }
    }

    void printNext(){
        for (auto &nt : this->grammar){
            cout << "Siguiente("<<nt.first->getKey() << ")={";
            for (auto &elem : nt.first->getNext()){
                cout << elem << ", ";
            }
            cout << "}\n";
        }
    }
    //id+id*id
    bool isAccepted(string strng) {
        LexAnalyzer  lexAna(strng);
        vector<Lex> lexical = lexAna.analyze();
        
        queue<string> input;
        for (const auto& c : lexical){
            if(c.t == ID){
                input.push("ID");
            }else{
                input.push(c.identifier);
            }
        }
        
        stack<Element*> s;
        s.push(new Terminal(DOLLAR));
        s.push(startingNT);
        
        while (!input.empty()){
            if (!s.top()->isTerminal()){
                auto* a = dynamic_cast<NonTerminal *>(s.top());
                auto rule = ll1[a][input.front()];
                if (rule[0]->getKey() == EXTRAER){
                    s.pop();
                    cerr << "output: extraer (error)" << endl;
                }
                else if (rule[0]->getKey() == EXPLORAR) {
                    input.pop();
                    cerr << "output: explorar (error)" << endl;
                }
                else{
                    s.pop();
                    for (int i = int(rule.size()-1); i >= 0; --i)
                        s.push(rule[i]);
                    cout << "output: " << a->getKey() << " -> ";
                    for (const auto &i : rule)
                        cout << i->getKey() << " ";
                    cout << endl;
                }
            }
            else {
                if (s.top()->getKey() == EPSILON){
                    cout << "output: match " << s.top()->getKey() << endl;
                    s.pop();
                }
                else {
                    if (s.top()->getKey() == input.front()){
                        cout << "output: match " << s.top()->getKey() << endl;
                        s.pop();
                        input.pop();
                    } else {
                        cerr << "output: terminal does not match" << endl;
                        return false;
                    }
                    
                }
            }
        }
        while (!s.empty()){
            if(s.size() == 1 && s.top()->getKey() == DOLLAR){
                break;
            }
            if (!s.top()->isTerminal()){
                bool hasEpsilon = false;
                for (auto &rule : grammar[dynamic_cast<NonTerminal *>(s.top())]){
                    if (rule[0]->getKey() == EPSILON){
                        cout << "output: match " << s.top()->getKey() << " -> " << EPSILON << endl;
                        s.pop();
                        hasEpsilon = true;
                        break;
                    }
                }
                if(!hasEpsilon){
                    cerr << "output: stack was not emptied" <<endl;
                    return false;
                }
            }
            else{
                cerr << "output: stack was not emptied" <<endl;
                return false;
            }
        }
        return true;
    }
};

#endif //LAB5_GRAMMAR_H