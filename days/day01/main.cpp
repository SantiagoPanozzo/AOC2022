#include <iostream>
#include "src/DataParser.h"

int main() {
    DataParser dataParser;
    dataParser.LoadData("../input/input.txt");
    int largest = dataParser.GetLargest();
    std::cout << "The largest amount of calories is " << largest << std::endl;
    return 0;
}
