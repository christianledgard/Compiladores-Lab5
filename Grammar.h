//
// Created by Christian Ledgard on 18/06/21.
//

#ifndef LAB5_GRAMMAR_H
#define LAB5_GRAMMAR_H

#include <map>
#include <vector>
#include "Element.h"

class Grammar{
private:

    std::map<NonTerminal*, vector<vector<Element*>>> grammar;
    NonTerminal* startingNT;
    
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
    
public:
    
    Grammar(const map<NonTerminal*, vector<vector<Element*>>> &grammar, NonTerminal* startingNT) : grammar(grammar), startingNT(startingNT){
        calculateFirst();
        caclulateNext();
    };
    
    
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
    
    
};

#endif //LAB5_GRAMMAR_H