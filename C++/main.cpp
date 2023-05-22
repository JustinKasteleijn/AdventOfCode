//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day11/DayEleven.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day11/test.txt");
    std::cout << AdventOfCode::DayEleven::parse("hepxcrrq", true) << std::endl;
    return 0;
}
