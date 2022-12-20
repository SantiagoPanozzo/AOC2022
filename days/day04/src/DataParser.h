//
// Created by snowiemischief on 19/12/22.
//

#ifndef DAY04_DATAPARSER_H
#define DAY04_DATAPARSER_H
#include <iostream>
#include <string>
#include <vector>

struct Range
{
    int from;
    int to;
};

struct AssignmentPair
{
    struct Range HalfOne;
    struct Range HalfTwo;
};

class DataParser {
public:
    void LoadData(std::string fileName);
    void Analize();
    int GetFullyContained();
    static bool TestContained(std::string input);
private:
    static struct AssignmentPair ParsePair(std::string str);
    std::vector<AssignmentPair> Data;
    static bool isSubset(Range Set, Range Subset);
    int _fullyContained;
};


#endif //DAY04_DATAPARSER_H
