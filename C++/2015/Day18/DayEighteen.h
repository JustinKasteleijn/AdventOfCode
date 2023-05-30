//
// Created by justi on 5/30/2023.
//

#ifndef ADVENTOFCODE_DAYEIGHTEEN_H
#define ADVENTOFCODE_DAYEIGHTEEN_H

#include <vector>
#include <string>

namespace AdventOfCode {

    using Grid = std::vector<std::vector<char>>;

    class DayEighteen {
        enum Lights {
            ON,
            OFF
        };
    public:
        static Grid parse(const std::vector<std::string> &data);

        static int solve(const std::vector<std::string> &data);

    private:
        static int adjacent(const Grid &, int i, int j);

        static Lights get_state(const char &current);

        static inline void turn_off(char &current) { current = '.'; };

        static inline void turn_on(char &current) { current = '#'; };

        static void turn_on_corners(Grid& grid);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYEIGHTEEN_H
