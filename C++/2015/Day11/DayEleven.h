//
// Created by justi on 5/22/2023.
//

#ifndef ADVENTOFCODE_DAYELEVEN_H
#define ADVENTOFCODE_DAYELEVEN_H

#include <string>

namespace AdventOfCode {

    class DayEleven {
    public:
        static std::string parse(const std::string &password, bool part2);

        static char next_letter(char &c);

        static std::string &next(std::string &password);

        static bool passes(const std::string &password);

        template<typename T>
        static auto reverse_range(T& container) {
            using ReverseIterator = typename T::reverse_iterator;
            return std::make_pair(ReverseIterator(container.end()), ReverseIterator(container.begin()));
        }
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYELEVEN_H
