//
// Created by justi on 6/1/2023.
//

#include "DayTwentyFive.h"

namespace AdventOfCode {
    int64_t DayTwentyFive::solve(int64_t code, int target_row, int target_col) {
        int64_t ny = target_row, nx = target_col;
        int x = 1, y = 1;
        for (int64_t i = 2; i < nx * ny * nx * ny; ++i) {
            if (y == 1) {
                y = x + 1;
                x = 1;
            } else {
                --y;
                ++x;
            }
            code = (code * 252533) % 33554393;
            if (y == ny && x == nx) {
                return code;
            }
        }
        return -1;
    }
} // AdventOfCode
