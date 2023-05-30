//
// Created by justi on 5/30/2023.
//

#ifndef ADVENTOFCODE_DAYSIXTEEN_H
#define ADVENTOFCODE_DAYSIXTEEN_H

#include <string>
#include <unordered_map>
#include <vector>

namespace AdventOfCode {

    class DaySixteen {
        static std::unordered_map<std::string, int32_t> real_sue;

    public:
        static int parse(std::ifstream &input, bool part2);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYSIXTEEN_H
