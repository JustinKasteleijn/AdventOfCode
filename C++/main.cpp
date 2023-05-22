//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day8/DayEight.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day8/test.txt");
    std::cout << AdventOfCode::DayEight::parse(file.to_vector(1000)) << std::endl;
    return 0;
}
