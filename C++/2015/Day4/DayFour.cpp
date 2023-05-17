//
// Created by justi on 5/16/2023.
//

#include "DayFour.h"
#include "lib/md5.h"

namespace AdventOfCode {
    int DayFour::solve(std::string data) {
        int index = 1;
        while (true) {
            std::string parse{data + std::to_string(index)};
            std::string md5sum{md5(parse)};
            if (md5sum.find("000000") == 0)
                break;
            ++index;
        }
        return index;
    }
} // AdventOfCode
