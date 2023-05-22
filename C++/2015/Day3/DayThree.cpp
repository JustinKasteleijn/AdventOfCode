//
// Created by justi on 5/16/2023.
//

#include <vector>
#include <set>
#include "DayThree.h"

namespace AdventOfCode {
    int DayThree::solve(const std::string &data) {
        std::set<std::pair<int, int> > s;
        int order = 0;
        std::pair<int, int> santa, robot;
        for (const char &ch: data) {
            switch (ch) {
                case '<':
                    order ? robot.first-- : santa.first--;
                    break;
                case '^':
                    order ? robot.second++ : santa.second++;
                    break;
                case '>':
                    order ? robot.first++ : santa.first++;
                    break;
                case 'v':
                    order ? robot.second-- : santa.second--;
                    break;
                default:
                    return -1;
            }
            order == 1 ? s.insert(santa) : s.insert(robot);
            order == 1 ? order = 0 : order = 1;
        }
        return static_cast<int>(s.size());
    }
} // AdventOfCode
