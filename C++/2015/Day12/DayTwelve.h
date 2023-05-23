//
// Created by justi on 5/23/2023.
//

#ifndef ADVENTOFCODE_DAYTWELVE_H
#define ADVENTOFCODE_DAYTWELVE_H

#include <vector>
#include <string>
#include <regex>

namespace AdventOfCode {

    class DayTwelve {
    public:
        static unsigned long parse(const std::string &data);

        static unsigned long parse2(const std::vector<std::string> &data);

        static int parse_numbers(const std::string &s);

        static int _parse(const std::string &s, unsigned long long int &pos);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYTWELVE_H
