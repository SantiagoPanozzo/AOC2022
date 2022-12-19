//
// Created by snowiemischief on 18/12/22.
//

#ifndef DAY03_DATAPARSER_H
#define DAY03_DATAPARSER_H

#include <iostream>
#include <string>
#include <vector>

struct DataPair
{
    std::string firstHalf;
    std::string secondHalf;
};

class DataParser {
public:
    void LoadData(std::string fileName);
    static int GetPriority(char charC);
    void SearchDuplicates();
    int CalculateTotal();
private:
    std::vector<DataPair> Data;
    std::vector<char> Duplicates;
};


#endif //DAY03_DATAPARSER_H
