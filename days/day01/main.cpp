#include <iostream>
#include "src/DataParser.h"

int main() {
    DataParser dataParser;
    dataParser.LoadData("../input/input.txt");
    dataParser.SortLargest();
    int largest = dataParser.GetLargest();
    int three = dataParser.ThreeLargest();
    std::cout << "The largest amount of calories is " << largest << std::endl;
    std::cout << "The three elves with the largest amount of calories amount to: " << three << std::endl;
    return 0;
}
