#include <iostream>
#include "File.h"
#include "2015/Day25/DayTwentyFive.h"

int main() {
    auto file = AdventOfCode::File("C:/Users/justi/AdventOfCode/C++/2015/Day24/test.txt");
    std::cout << AdventOfCode::DayTwentyFive::solve(20151125, 2981, 3075) << std::endl;
    return 0;
}
