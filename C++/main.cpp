//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day9/DayNine.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day9/test.txt");
    std::cout << AdventOfCode::DayNine::parse2(file.to_vector(1000)) << std::endl;
    return 0;
}
