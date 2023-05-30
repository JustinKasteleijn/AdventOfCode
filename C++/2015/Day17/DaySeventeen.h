//
// Created by justi on 5/30/2023.
//

#ifndef ADVENTOFCODE_DAYSEVENTEEN_H
#define ADVENTOFCODE_DAYSEVENTEEN_H


#include <vector>
#include <string>

namespace AdventOfCode {
    class DaySeventeen {
    public:
        static int parse(const std::vector<std::string> &data, int target, bool part2);

    private:
        static int findCombinations(const std::vector<int> &numbers, int target);

        static int _part2(std::vector<int> containers, std::vector<int> &sizes, int goal, int values_in_goal);

        static int _count(int part2, std::vector<int> &sizes);
    };
}


#endif //ADVENTOFCODE_DAYSEVENTEEN_H
