
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
//                                                        {Z, {{X,Y,Z},{d}}},
//                                                        {Y, {{c},{ep}}},
//                                                        {X, {{Y},{a}}}
//                                                    }; 
//

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
//                                                        {SP, {{S}}},
//                                                        {S, {{A,w,S},{x,S}}},
//                                                        {A, {{B,C},{y}}},
//                                                        {B, {{z,B},{z}}},
//                                                        {C, {{ep},{y},{D}}},
//                                                        {D, {{ep},{z,D}}}
//
//                                                    }; 


    auto S = new NonTerminal("S");
    auto SP = new NonTerminal("SP");
    auto T = new NonTerminal("T");
    auto TP = new NonTerminal("TP");
    auto F = new NonTerminal("F");
    auto ID = new Terminal("ID");
    auto LB = new Terminal("{");
    auto RB = new Terminal("}");
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
//
//    auto E = new NonTerminal("E");
//    auto T = new NonTerminal("T");
//    auto EP = new NonTerminal("E'");
//    auto TP = new NonTerminal("T'");
//    auto F = new NonTerminal("F");
//    auto mas = new Terminal("+");
//    auto ast = new Terminal("*");
//    auto LB = new Terminal("(");
//    auto RB = new Terminal(")");
//    auto id = new Terminal("id");
//    auto ep = new Terminal(EPSILON);
//
//    map<NonTerminal*, vector<vector<Element*>>> rule1{
//                                                        {E, {{T,EP}}},
//                                                        {EP, {{mas,T,EP},{ep}}},
//                                                        {T, {{F,TP}}},
//                                                        {TP, {{ast,F,TP},{ep}}},
//                                                        {F, {{LB,E,RB},{id}}}
//    };
    auto grammar1 = new Grammar(rule1, S, true);
    
    //grammar1->getFirsts();
    grammar1->printFirst();
    std::cout << "------------------------------------" << std::endl;
    //grammar1->getNexts();
    grammar1->printNext();
    std::cout << "------------------------------------" << std::endl;
    grammar1->printLL1();
    std::cout << "------------------------------------" << std::endl;
    cout << grammar1->isAccepted("{int x ; float *y ; }");




    return 0;
}