#include <iostream>
#include "src/DataParser.h"

int main() {
    //DataParser::TestContained("9-9,9-9");
    DataParser dataParser;
    dataParser.LoadData("../input/input.txt");
    dataParser.Analize();
    int result = dataParser.GetFullyContained();
    std::cout << result << " elves' assignments fully contain its pairs'" << std::endl;
    return 0;
}
