//
// Created by Christian Ledgard on 18/06/21.
//

#ifndef LAB5_ELEMENT_H
#define LAB5_ELEMENT_H
#define EPSILON "ϵ"
#define DOLLAR "$"


#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

class Element{
public:
    string key;
    explicit Element(string key) : key(std::move(key)) {}
    
    virtual set<string> getFirstSet() = 0;
    virtual bool isEpsilonInFirst() = 0;
    virtual bool addToNext(set<string> newNext) = 0;
    virtual set<string> getNext() = 0;
    virtual bool isTerminal() = 0;
    
    const string &getKey() const {
        return key;
    }
};

class Terminal: public Element{

public:
    Terminal(string key) : Element(key) { this->key = key;}
    
    set<string> getFirstSet() override {
        return set<string>{this->key};
    }

    bool isEpsilonInFirst() override {
        return Terminal::key == EPSILON;
    }
    
    bool addToNext(set<string> newNext) override{
        return false;
    }

    set<string> getNext() override{
        return set<string>{};
    }
    
    bool isTerminal() override{
        return true;
    }
};

class NonTerminal: public Element{
protected:
    set<string> first = set<string>{};
    set<string> next = set<string>{};
public:
    NonTerminal(string key) : Element(key) { this->key = key;}
    
    set<string> getFirstSet() override {
        set<string> temp;
        for (const auto &e : NonTerminal::first)
            if (e != EPSILON)
                temp.insert(e);
        return temp;    
    }

    const set<string> &getFirst() const {
        return first;
    }

    set<string> getNext() override {
        return next;
    }

    bool addToFirst(set<string> newFirst) {
        auto size = NonTerminal::first.size();
        for(const auto &element : newFirst){
            NonTerminal::first.insert(element);
        }
        return NonTerminal::first.size() != size;
    }

    bool addToNext(set<string> newNext) override{
        auto size = NonTerminal::next.size();
        for(const auto &element : newNext){
            NonTerminal::next.insert(element);
        }
        return NonTerminal::next.size() != size;
    }
    
    bool isEpsilonInFirst() override{
        return NonTerminal::first.find(EPSILON) != NonTerminal::first.end();
    }

    bool isTerminal() override{
        return false;
    }

};

#endif //LAB5_ELEMENT_H
