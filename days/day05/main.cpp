#include <iostream>
#include "src/DataParser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataParser dataParser;
    dataParser.LoadData("../input/input.txt");
    dataParser.ParseData();
    //dataParser.PrintData();
    std::vector<Movement> moves = dataParser.GetMoves();
    Crane::AutoMove(moves);
    std::vector<Crate> tops = dataParser.GetAllTops();
    for(auto i: tops)
    {
        std::cout << i.ID;
    }
    std::cout << std::endl;
    return 0;
}
