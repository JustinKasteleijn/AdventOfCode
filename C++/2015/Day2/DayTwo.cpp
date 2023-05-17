//
// Created by justi on 5/16/2023.
//

#include "DayTwo.h"
#include <algorithm>

namespace AdventOfCode {
    unsigned long DayTwo::solve(const std::vector<std::string> &data) {
        unsigned long total = 0;
        for (const std::string &line: data) {
            Dimensions dimensions = DayTwo::parse_dimensions(line);
            std::vector<int> d = {dimensions.l, dimensions.w, dimensions.h};
            std::sort(d.begin(), d.end());
            int wrap = (d[0]*2) + (d[1]*2);
            int bow = dimensions.l * dimensions.w * dimensions.h;
            total += (wrap + bow);
        }
        return total;
    }

    Dimensions DayTwo::parse_dimensions(const std::string &dimensions) {
        std::vector<int> result;
        result.reserve(3);
        std::size_t startPos = 0;
        std::size_t foundPos;

        while ((foundPos = dimensions.find(120, startPos)) != std::string::npos) {
            result.push_back(std::stoi(dimensions.substr(startPos, foundPos - startPos)));
            startPos = foundPos + 1;
        }

        result.push_back(std::stoi(dimensions.substr(startPos)));

        return {result.at(0), result.at(1), result.at(2)};
    }

} // AdventOfCode
