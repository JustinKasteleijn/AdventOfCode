//
// Created by justi on 5/24/2023.
//

#ifndef ADVENTOFCODE_DAYFOURTEEN_H
#define ADVENTOFCODE_DAYFOURTEEN_H

#include <string>
#include <vector>
#include <map>

namespace AdventOfCode {

    class DayFourteen {
    public:
        struct Reindeer {
            std::string name;
            int speed;
            int stamina;
            int rest_period;
            int remaining_resting_period;
            int remaining_stamina;
        };
    public:
        static int parse(const std::vector<std::string> &data, int duration, bool part2);

    private:
        static std::vector<std::string> findKeysWithMaxValue(const std::map<std::string, int> &scoring);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYFOURTEEN_H
