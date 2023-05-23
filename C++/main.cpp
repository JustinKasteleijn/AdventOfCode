//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day13/DayThirteen.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day13/test.txt");
    std::cout << AdventOfCode::DayThirteen::parse(file.to_vector(50), true) << std::endl;
    return 0;
}
