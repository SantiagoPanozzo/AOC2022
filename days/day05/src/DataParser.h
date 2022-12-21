//
// Created by snowiemischief on 20/12/22.
//

#ifndef DAY05_DATAPARSER_H
#define DAY05_DATAPARSER_H
#include "Stack.h"
#include <list>
#include <vector>
#include <string>
#include "Crane.h"

class DataParser
{
public:
    std::vector<Stack> GetStacks();
    bool LoadData(std::string fileName);
    bool ParseData();
    std::vector<Movement> GetMoves();
    std::vector<Crate> GetAllTops();
    void PrintData();
private:
    bool ParseActions();
    bool ParseStack();
    int GetStackNumber();
    Stack* GetStackFromID(char id);
    std::vector<std::string> _rawData;
    std::vector<Stack> _stacks;
    std::vector<Movement> _actions;
};


#endif //DAY05_DATAPARSER_H
