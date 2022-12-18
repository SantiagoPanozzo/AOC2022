//
// Created by snowiemischief on 17/12/22.
//

#include "DataParser.h"
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

void DataParser::LoadData(string fileName)
{
    ifstream inputFile(fileName);
    string inputData;
    vector<vector<string>> allData;
    vector<string> tempVect;
    while(getline(inputFile, inputData))
    {
        if(!(inputData.empty()))
        {
            tempVect.push_back(inputData);
        }
        else {
            allData.push_back(tempVect);
            tempVect.clear();
        }
    }
    allData.push_back(tempVect);

    /*for(int j = 0; j < allData.size(); j++)
    {
        vector<string> thisOne = allData.at(j);
        for(int k = 0; k < thisOne.size(); k ++) {
            cout << "\"" << thisOne.at(k) << "\" ";
        }
        cout << endl;
    }*/

    this->Data = allData;
}

int DataParser::GetLargest()
{
    vector<vector<string>> input = DataParser::Data;
    int Calories[input.size()];
    memset(Calories, 0, sizeof(Calories));
    int tempInt;
    for(int i = 0; i < input.size(); i++)
    {
        vector<string> current = input.at(i);

        for (int j = 0; j < current.size(); j++)
        {
            tempInt = std::stoi(current.at(j));
            Calories[i] += tempInt;
        }
    }

    int largest = Calories[0];

    for (int k = 0; k < input.size(); k++)
    {
        //cout << Calories[k] << endl;
        if(Calories[k] > largest) largest = Calories[k];
    }

    return largest;
}

//string DataParser::ToArray(std::vector<std::vector<std::string>> input){}

