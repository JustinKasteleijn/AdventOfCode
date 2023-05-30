//
// Created by justi on 5/15/2023.
//

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
        int floor = 0;
        int c = 0;
        for (const char &ch: data) {
            ++c;
            if (ch == '(') {
                ++floor;
            } else {
                --floor;
            }

            if (floor == -1) {
                return c;
            }
        }
        return floor;
    }
} // AdventOfCode
