//
// Created by justi on 5/22/2023.
//

#ifndef ADVENTOFCODE_DAYNINE_H
#define ADVENTOFCODE_DAYNINE_H

#include <vector>
#include <string>
#include <map>

namespace AdventOfCode {
    class DayNine {
        using Distances = std::map<std::string, std::map<std::string, int>>;
    public:
        static int parse(const std::vector<std::string> &data);

        static int parse2(const std::vector<std::string> &data);
    };
} // AdventOfCode

#endif //ADVENTOFCODE_DAYNINE_H
