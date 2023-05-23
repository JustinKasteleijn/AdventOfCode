//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day12/DayTwelve.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day12/test.txt");
    std::cout << AdventOfCode::DayTwelve::parse2(file.to_vector(7500)) << std::endl;
    return 0;
}
