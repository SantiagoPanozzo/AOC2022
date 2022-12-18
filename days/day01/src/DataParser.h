//
// Created by snowiemischief on 17/12/22.
//

#include <iostream>
#include <vector>
#include <string>
#ifndef DAY01_DATAPARSER_H
#define DAY01_DATAPARSER_H

class DataParser {

public:
    void LoadData(std::string fileName);
    int GetLargest();
    int ThreeLargest();
    void SortLargest();

private:
    int Largest;
    int SecondL;
    int ThirdL;
    std::vector<std::vector<std::string>> Data;
};



#endif //DAY01_DATAPARSER_H
