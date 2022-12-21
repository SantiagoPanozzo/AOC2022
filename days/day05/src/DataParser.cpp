//
// Created by snowiemischief on 20/12/22.
//

#include "DataParser.h"
#include <fstream>
#include <iostream>
#include "Crane.h"

using namespace std;

bool DataParser::LoadData(std::string fileName)
{
    bool success = false;
    fstream inputFile (fileName);
    string inputData;
    vector<string> *rawData = &(DataParser::_rawData);
    while(getline(inputFile, inputData)) {
        success = true;
        rawData->push_back(inputData);
    }
    return success;
}

int DataParser::GetStackNumber()
{
    vector<string> rawData = DataParser::_rawData;
    int stacksAmount = (rawData.at(0).size()+1)/4;

    for(auto lines : rawData)
    {
        if(lines[0] == '[')
            if((lines.size()+1)/4 > stacksAmount)
                stacksAmount = (lines.size()+1)/4;
    }
    return stacksAmount;
}

bool DataParser::ParseStack()
{
    bool success = false;
    vector<string> rawData = DataParser::_rawData;
    vector<Stack> stacks;
    int stacksAmount = DataParser::GetStackNumber();
    for (int i = 0; i < stacksAmount; i++){
        Stack tempStack = {};
        tempStack.ID = char(i+1)+'0';
        stacks.push_back(tempStack);
    }

    Crate* tempCrate;
    for(auto lines : rawData)
    {
        if(lines[0] == 'm') continue;
        if(lines[1] == '1') continue;
        stacksAmount = (lines.size()+1)/4;
        for(int i = 1; i < stacksAmount*4; i+=4)
        {
            if((lines[i] != ' ')){
                int j = i;
                tempCrate = new Crate();
                tempCrate->ID = lines[i];
                if(j == 1) j = 0;
                if(j >= 4) j = i/4;
                stacks.at(j).AddToBack(*tempCrate);
                success = true;
            }
        }
    }
    DataParser::_stacks = stacks;
    return success;
}

bool DataParser::ParseActions()
{
    bool success = false;
    vector<string> rawData = DataParser::_rawData;
    vector<Movement> actions;
    for(auto line : rawData)
    {
        success = true;
        if(line[0] == 'm') {
            string tempAmount = "";
            bool loaded = false;
            int continueFrom;
            for(int i = 5 ; i < line.size(); i++)
            {
                if(line[i] == ' ') loaded = true;
                if (loaded) continue;
                tempAmount.push_back(line[i]);
                continueFrom = i+1;
            }
            int amount = stoi(tempAmount);
            //int amount = int(line[5]-'0');
            Stack* from = DataParser::GetStackFromID(line[continueFrom + 6]);
            Stack* to = DataParser::GetStackFromID(line[continueFrom + 11]);
            Movement tempMovement = { from, to, amount };
            actions.push_back(tempMovement);
        }
    }
    DataParser::_actions = actions;
    return success;
}

bool DataParser::ParseData()
{
    bool stack = DataParser::ParseStack();
    bool actions = DataParser::ParseActions();
    return (stack && actions);
}

void DataParser::PrintData()
{
    vector<Stack>* stacks = &(DataParser::_stacks);
    vector<Movement>* actions = &(DataParser::_actions);
    for(auto stack : *stacks)
    {
        std::cout << "Stack " << stack.ID << ": ";
        for(auto crate : stack.GetContent())
        {
            std::cout << crate.ID << " - ";
        }
        std::cout << std::endl;
    }
    for(auto action : *actions)
    {
        cout << "move " << action.amount << " from " << action.from->ID << " to " << action.to->ID << endl;
    }
}

Stack* DataParser::GetStackFromID(char id)
{
    vector<Stack>* stacks = &(DataParser::_stacks);
    for(int i = 0; i < stacks->size(); i++)
    {
        Stack* j = &(stacks->at(i));
        if(j->ID == id) {
            return j;
        }
    }
}

std::vector<Crate> DataParser::GetAllTops()
{
    vector<Stack>* stacks = &(DataParser::_stacks);
    vector<Crate> tops;
    for(int i = 0; i < stacks->size(); i++)
    {
        tops.push_back(*(stacks->at(i).WhoOnTop()));
    }
    return tops;
}

std::vector<Movement> DataParser::GetMoves() { return DataParser::_actions; }