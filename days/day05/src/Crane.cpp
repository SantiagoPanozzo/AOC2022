//
// Created by snowiemischief on 20/12/22.
//

#include "Crane.h"
#include <iostream>

void Crane::Move(Movement movement)
{
    Crate tempCrate;
    Stack* from = movement.from;
    Stack* to = movement.to;
    int amount = movement.amount;
    for( int i = 0; i < amount; i++ )
    {
        std::cout << "moved 1 from " << movement.from->ID << " to " << movement.to->ID << std::endl;
        tempCrate = from->PopFromTop();
        to->AddOnTop(tempCrate);
    }
}

void Crane::AutoMove(std::vector<Movement> moves)
{
    for(auto movement: moves)
    {
        //std::cout << "move " << movement.amount << " from " << movement.from->ID << " to " << movement.to->ID << std::endl;
        Crane::Move(movement);
    }
}



