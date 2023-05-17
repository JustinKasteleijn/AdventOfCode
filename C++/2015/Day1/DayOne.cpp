//
// Created by justi on 5/15/2023.
//

#include "DayOne.h"

namespace AdventOfCode {

    int DayOne::solve(const std::string &data) {
        int floor = 0;
        for(std::size_t i = 0; i < data.length(); ++i) {
            if (floor == -1) {
                return (int)i;
            }
            floor += data[i] == '(' ? 1 : -1;
        }
        return floor;
    }
} // AdventOfCode
