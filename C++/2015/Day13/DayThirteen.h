//
// Created by justi on 5/23/2023.
//

#ifndef ADVENTOFCODE_DAYTHIRTEEN_H
#define ADVENTOFCODE_DAYTHIRTEEN_H

#include <vector>
#include <string>
#include <map>

namespace AdventOfCode {

    class DayThirteen {
        using Happiness = std::map<std::string, std::map<std::string, int>>;
    public:
        static int parse(const std::vector<std::string> &data, bool part2);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYTHIRTEEN_H
