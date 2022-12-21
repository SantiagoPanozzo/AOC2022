//
// Created by snowiemischief on 20/12/22.
//

#ifndef DAY05_CRANE_H
#define DAY05_CRANE_H
#include <list>
#include "Stack.h"

struct Movement
{
    Stack* from;
    Stack* to;
    int amount;
};

class Crane {
public:
    static void Move(Movement movement);
    static void AutoMove(std::vector<Movement> moves);
};


#endif //DAY05_CRANE_H
