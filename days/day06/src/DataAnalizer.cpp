//
// Created by snowiemischief on 23/12/22.
//

#include "DataAnalizer.h"
#include <iostream>

int DataAnalizer::AnalizeString(std::string input)
{
    std::string lastFour = "";
    for(int i = 0; i < input.size(); i ++)
    {
        lastFour.push_back(input[i]);
        if(i >= 4) lastFour.erase(0, sizeof(char));

        if(i >= 3 && DataAnalizer::AnalizeStep(lastFour))
            return i + 1;
    }
    return -1;
}

bool DataAnalizer::AnalizeStep(std::string stepInput)
{
    for(int i = 0; i < stepInput.size(); i++)
    {
        for(int j = 0; j < stepInput.size(); j++)
        {
            if(i == j) continue;
            if(stepInput[i] == stepInput[j]) return false;
        }
    }
    return true;
}