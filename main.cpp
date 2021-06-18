#include <iostream>

#include "Grammar.h"

int main() {

    NonTerminal nt("A");
    Terminal t("a");
    
    Grammar gr(unordered_map<NonTerminal, vector<vector<Element>>>({
        {nt,vector<vector<Element>>{vector<Element>{t,t,nt}}}
    }));

    
    auto grammar = new Grammar{};

    auto ntp = new NonTerminal("A");
    auto tp = new Terminal("a");

    vector<vector<Element>> second{{nt},{nt},{nt}};

    
    gr.getFirsts();
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/* 
 *          Elemento:
 * 
 *          Terminal
 *          NoTerminal
 *              vector<Terminal> primeros
 * 
 * 
 *          unordered_map<NoTerminal, vector<vector<Elemento>>
 *          
 *           {
 *              A : [[a,B,z], e],
 *              B : [[b], [A,c]]
 *           }
 * 
 * 
 *          
 *          for noTerminal in gramatica:
 *              for regla in noTerminal:
 *                 if regla[0] is terminal
 *                   noTerminal.primeros.pushback(regla[0]),
 *                   else noTerminal.primeros.insert(regla[0].primero)
 * 
 * */