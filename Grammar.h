//
// Created by Christian Ledgard on 18/06/21.
//

#ifndef LAB5_GRAMMAR_H
#define LAB5_GRAMMAR_H

#include <unordered_map>
#include <vector>
#include "Element.h"

class Grammar{
private:

    std::unordered_map<NonTerminal, vector<vector<Element>>> grammar;

public:
    Grammar(const unordered_map<NonTerminal, vector<vector<Element>>> &grammar) : grammar(grammar) {}

//    Terminal a = Terminal("a");
//    NonTerminal A = NonTerminal("A");
    void getFirsts(){
        bool changes = false;
        for (auto &nt : this->grammar){
            for (vector<Element>& rule : nt.second){
                bool addEpsilon = true;
                for (Element& element : rule){
                    NonTerminal a = nt.first;
                    changes = a.addToFirst(element.getFirstSet());
                    if(element.isEpsilonInFirst()){addEpsilon = false; break;}
                }
                if (addEpsilon) {
                    NonTerminal a = nt.first;
                    changes =a.addToFirst(set<string>{"string"});
                }
            }
        if (changes) getFirsts();
        }
    }
    
    void getSeconds(){
    }
};

#endif //LAB5_GRAMMAR_H