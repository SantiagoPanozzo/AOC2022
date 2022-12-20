//
// Created by snowiemischief on 19/12/22.
//

#include "DataParser.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void DataParser::LoadData(std::string fileName)
{
    fstream inputFile (fileName);
    string inputData;
    vector<AssignmentPair> data;
    AssignmentPair tempPair;

    while(getline(inputFile,inputData))
    {
        tempPair = DataParser::ParsePair(inputData);
        data.push_back(tempPair);
    }

    DataParser::Data = data;
}

void DataParser::Analize()
{
    vector<AssignmentPair>* Data = &(DataParser::Data);
    int fullyContained = 0;

    for(auto pair : *Data)
    {
        //cout << pair.HalfOne.from << "-" << pair.HalfOne.to << ":" <<
        //pair.HalfTwo.from << "-" << pair.HalfTwo.to << endl;
        if(DataParser::isSubset(pair.HalfOne,pair.HalfTwo)) {
            fullyContained += 1;
            continue;
            //cout << "yes" << endl;
        }
        if(DataParser::isSubset(pair.HalfTwo,pair.HalfOne)) {
            fullyContained += 1;
            continue;
            //cout << "yes" << endl;
        }
    }

    DataParser::_fullyContained = fullyContained;
}

struct AssignmentPair DataParser::ParsePair(std::string str)
{
    string firstFrom = "";
    string firstTo = "";
    string secondFrom = "";
    string secondTo = "";
    string* loadTo = &(firstFrom);
    for (auto i : str)
    {
        if(i == ',') {
            loadTo = &(secondFrom);
            continue; }
        if(i == '-') {
            if(loadTo == &(firstFrom)) loadTo = &(firstTo);
            if(loadTo == &(secondFrom)) loadTo = &(secondTo);
            continue;
        }
        loadTo->push_back(i);
    }
    struct Range FirstHalf = { stoi(firstFrom), stoi(firstTo) } ;
    struct Range SecondHalf = { stoi(secondFrom), stoi(secondTo) } ;
    struct AssignmentPair Output = { FirstHalf, SecondHalf };
    return Output;
}

bool DataParser::isSubset(Range Set, Range Subset)
{
    if((Set.from <= Subset.from) && (Set.to >= Subset.to))
        return true;
    return false;
}

int DataParser::GetFullyContained() { return DataParser::_fullyContained; }

bool DataParser::TestContained(std::string input)
{
    DataParser parser;
    AssignmentPair pair = DataParser::ParsePair(input);
    Range r1 = pair.HalfOne;
    Range r2 = pair.HalfTwo;

    if(DataParser::isSubset(r1,r2))
    {
        cout << "r2 is subset of r1" << endl;
        cout << r1.from << " <= " << r2.from << " && " << r1.to << " >= " << r2.to << endl;
        return true;
    } else {
        cout << "r2 is not a subset of r1" << endl;
        cout << r1.from << " > " << r2.from << " or " << r1.to << " < " << r2.to << endl;
    }
    if(DataParser::isSubset(r2,r1))
    {
        cout << "r1 is subset of r2" << endl;
        cout << r2.from << " <= " << r1.from << " && " << r2.to << " >= " << r1.to << endl;
        return true;
    } else {
        cout << "r1 is not a subset of r2" << endl;
        cout << r2.from << " > " << r1.from << " or " << r2.to << " < " << r1.to << endl;
    }
    return false;
}