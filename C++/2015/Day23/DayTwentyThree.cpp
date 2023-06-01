//
// Created by justi on 6/1/2023.
//

#include "DayTwentyThree.h"

namespace AdventOfCode {
    int DayTwentyThree::parse(const std::vector<std::string> &data) {
        //return Computer{}.run(data);
        Computer computer;
        computer.reg[0] = 1;
        return computer.run(data);
    }
} // AdventOfCode
