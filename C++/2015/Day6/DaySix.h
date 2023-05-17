//
// Created by justi on 5/17/2023.
//

#ifndef C___DAYSIX_H
#define C___DAYSIX_H

#include <utility>
#include <vector>
#include <string>

namespace AdventOfCode {
    enum Event {
        ON,
        OFF,
        TOGGLE
    };

    struct Coordinate {
        int x, y;
    };

    struct Coordinates {
        Coordinate start;
        Coordinate end;
    };

    using Instructions = std::pair<Event, Coordinates>;

    class DaySix {
    public:
        static int solve(const std::vector<std::string> &data);
        static unsigned long solve2(const std::vector<std::string> &data);

    private:
        static std::vector<Instructions> parse(const std::vector<std::string> &data);

        static Coordinate getCoordinates(const std::string &line);
    };

} // AdventOfCode

#endif //C___DAYSIX_H
