//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day1/DayOne.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day1/test.txt");
    std::cout << AdventOfCode::DayOne::solve2(file.to_string()) << std::endl;
    return 0;
}
