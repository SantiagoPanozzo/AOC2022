#include <iostream>
#include "src/DataParser.h"
int main() {
    DataParser dataParser;
    dataParser.LoadData("../input/input.txt");
    dataParser.SearchDuplicates();
    int total = dataParser.CalculateTotal();
    std::cout << "Total: " << total << std::endl;
    return 0;
}
