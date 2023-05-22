//
// Created by justi on 5/22/2023.
//

#ifndef ADVENTOFCODE_DAYEIGHT_H
#define ADVENTOFCODE_DAYEIGHT_H

#include <vector>
#include <string>

namespace AdventOfCode {

    class DayEight {
    public:
        static int parse(const std::vector<std::string>& data);

        static int character_count(const std::string &line);

        static int character_count2(const std::string &line);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYEIGHT_H
