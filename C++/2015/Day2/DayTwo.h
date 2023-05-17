//
// Created by justi on 5/16/2023.
//

#ifndef C___DAYTWO_H
#define C___DAYTWO_H

#include <string>
#include <vector>

namespace AdventOfCode {

    struct Dimensions {
        int l, w, h;
    };

    class DayTwo {
        static Dimensions parse_dimensions(const std::string &dimensions);

    public:
        static unsigned long solve(const std::vector<std::string> &data);
    };

} // AdventOfCode

#endif //C___DAYTWO_H
