//
// Created by snowiemischief on 20/12/22.
//

#ifndef DAY05_STACK_H
#define DAY05_STACK_H
#include <list>
#include <vector>
#include "Crate.h"

class Stack {
public:
    Crate* WhoOnTop();
    void AddOnTop(Crate crate);
    void AddToBack(Crate crate);
    Crate PopFromTop();
    std::list<Crate> GetContent();
    char ID;
private:
    std::list<Crate> _content;
};


#endif //DAY05_STACK_H
