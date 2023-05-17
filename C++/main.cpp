//
// Created by justi on 5/16/2023.
//
#include <iostream>
#include "File.h"
#include "2015/Day7/DaySeven.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day7/test.txt");
    std::cout << AdventOfCode::DaySeven::parse(file.to_vector(1000)).at(0).from_address_x.name << std::endl;
    return 0;
}
