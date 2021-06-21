
#include "Grammar.h"

int main() {
//    auto Z = new NonTerminal("Z");
//    auto X = new NonTerminal("X");
//    auto Y = new NonTerminal("Y");
//    auto d = new Terminal("d");
//    auto c = new Terminal("c");
//    auto a = new Terminal("a");
//    auto ep = new Terminal(EPSILON);
//
//    map<NonTerminal*, vector<vector<Element*>>> rule1{
//                                                                    {Z, {{X,Y,Z},{d}}},
//                                                                    {Y, {{c},{ep}}},
//                                                                    {X, {{Y},{a}}}
//                                                                }; 


//    auto SP = new NonTerminal("SP");
//    auto S = new NonTerminal("S");
//    auto A = new NonTerminal("A");
//    auto B = new NonTerminal("B");
//    auto C = new NonTerminal("C");
//    auto D = new NonTerminal("D");
//    auto w = new Terminal("w");
//    auto x = new Terminal("x");
//    auto y = new Terminal("y");
//    auto z = new Terminal("z");
//    auto ep = new Terminal(EPSILON);
//
//    map<NonTerminal*, vector<vector<Element*>>> rule1{
//                                                                    {SP, {{S}}},
//                                                                    {S, {{A,w,S},{x,S}}},
//                                                                    {A, {{B,C},{y}}},
//                                                                    {B, {{z,B},{z}}},
//                                                                    {C, {{ep},{y},{D}}},
//                                                                    {D, {{ep},{z,D}}}
//
//                                                            }; 


    auto S = new NonTerminal("S");
    auto SP = new NonTerminal("SP");
    auto T = new NonTerminal("T");
    auto TP = new NonTerminal("TP");
    auto F = new NonTerminal("F");
    auto ID = new Terminal("ID");
    auto LB = new Terminal("LB");
    auto RB = new Terminal("RB");
    auto PC = new Terminal(";");
    auto w = new Terminal("*");
    auto ep = new Terminal(EPSILON);

    map<NonTerminal*, vector<vector<Element*>>> rule1{
                                                        {S, {{LB,SP}}},
                                                        {SP, {{T,ID,PC,F,SP},{ep}}},
                                                        {F, {{RB},{ep}}},
                                                        {T, {{ID,TP}}},
                                                        {T, {{ID},{TP}}},
                                                        {TP, {{w,TP},{ep}}}
                                                     }; 
    auto grammar1 = new Grammar(rule1, S);
    
    //grammar1->getFirsts();
    grammar1->printFirst();
    std::cout << "------------------------------------" << std::endl;
    //grammar1->getNexts();
    grammar1->printNext();
    
    
    
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
 *          map<NoTerminal, vector<vector<Elemento>>
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