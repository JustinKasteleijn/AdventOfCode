//
// Created by justi on 5/15/2023.
//

#include <numeric>
#include "DayOne.h"

namespace AdventOfCode {

    int DayOne::solve(const std::string &data) {
        int floor = 0;
        for (std::size_t i = 0; i < data.length(); ++i) {
            if (floor == -1) {
                return static_cast<int>(i);
            }
            floor += (data[i] == '(');
        }
        return floor;
    }

    int DayOne::solve2(const std::string &data) {
        return std::accumulate(data.begin(), data.end(), 0, [](int currentFloor, char c) {
            return currentFloor + (c == '(' ? 1 : 0);
        });
    }
} // AdventOfCode
