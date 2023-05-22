//
// Created by justi on 5/22/2023.
//

#ifndef ADVENTOFCODE_DAYTEN_H
#define ADVENTOFCODE_DAYTEN_H

#include <vector>
#include <string>

namespace AdventOfCode {

    class DayTen {
    public:
        static int parse(const std::vector<std::string> &data, int process);

    private:
        struct Occurrences {
            std::string occurrences;
            std::string digit;
        };

        static std::vector<Occurrences> get_occurrences(const std::string &line);

        static std::string parse_occurrences(const std::vector<Occurrences> &occurrences);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYTEN_H
