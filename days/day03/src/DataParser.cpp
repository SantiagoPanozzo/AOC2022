//
// Created by snowiemischief on 18/12/22.
//

#include <fstream>
#include "DataParser.h"
#include <cstring>
#include <algorithm>

using namespace std;

void DataParser::LoadData(std::string fileName)
{
    ifstream inputFile (fileName);
    string inputData;
    vector<DataPair> DataPairs;
    string halfOne;
    string halfTwo;
    struct DataPair current;

    while(getline(inputFile,inputData))
    {
        halfOne.clear();
        halfTwo.clear();
        for(int i = 0; i < (inputData.size()+1)/2; i++)
        {
            halfOne.push_back(inputData[i]);
        }
        for(int i = (inputData.size()+1)/2; i < inputData.size()+1; i++)
        {
            halfTwo.push_back(inputData[i]);
        }
        current = { halfOne, halfTwo };
        //cout << "\"" << current.firstHalf << "\" " << "\"" << current.secondHalf << "\"" << endl;
        DataPairs.push_back(current);
    }

    DataParser::Data = DataPairs;
}

void DataParser::SearchDuplicates()
{
    vector<DataPair>* Data = &(DataParser::Data);
    vector<char>* Duplicates = &(DataParser::Duplicates);
    bool found;
    for(auto i: *Data)
    {
        found = false;
        for(auto j: i.firstHalf)
        {
            if(!found){
                if(i.secondHalf.contains(j)){
                    Duplicates->push_back(j);
                    found = true;
                }
            }
        }
    }

    /*for(auto i: *Duplicates)
    {
        cout << i << endl;
    }*/
}

int DataParser::GetPriority(char charC)
{
    const char Letters[53] = {' ','a','b','c','d','e','f','g','h','i',
                              'j','k','l','m','n','o','p','q','r',
                              's','t','u','v','w','x','y','z','A',
                              'B','C','D','E','F','G','H','I','J',
                              'K','L','M','N','O','P','Q','R','S',
                              'T','U','V','W','X','Y','Z'};
    int n = sizeof(Letters)/sizeof(Letters[0]);
    auto itr = find(Letters,Letters+n,charC);
    if(itr != end(Letters))
    {
        return distance(Letters,itr);
    }
    return -1;
}

int DataParser::CalculateTotal()
{
    vector<char> *Duplicates = &(DataParser::Duplicates);
    int total = 0;
    for(auto i: *Duplicates)
    {
        total += DataParser::GetPriority(i);
    }
    return total;
}