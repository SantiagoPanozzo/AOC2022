//
// Created by snowiemischief on 23/12/22.
//

#include "ExampleTest.h"
#include "../src/DataAnalizer.h"
#include <iostream>

bool ExampleTest::RunTests()
{
    if(ExampleTest::Case0() && ExampleTest::Case1() && ExampleTest::Case2() && ExampleTest::Case3() && ExampleTest::Case4())
    {
        std::cout << "All tests passed" << std::endl;
        return true;
    }
    return false;
}

bool ExampleTest::Case0(){
    int expected = 7;
    int result = DataAnalizer::AnalizeString("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
    return (expected == result);
}

bool ExampleTest::Case1(){
    int expected = 5;
    int result = DataAnalizer::AnalizeString("bvwbjplbgvbhsrlpgdmjqwftvncz");
    return (expected == result);
}

bool ExampleTest::Case2(){
    int expected = 6;
    int result = DataAnalizer::AnalizeString("nppdvjthqldpwncqszvftbrmjlhg");
    return (expected == result);
}

bool ExampleTest::Case3(){
    int expected = 10;
    int result = DataAnalizer::AnalizeString("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");
    return (expected == result);
}

bool ExampleTest::Case4(){
    int expected = 11;
    int result = DataAnalizer::AnalizeString("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw");
    return (expected == result);
}
