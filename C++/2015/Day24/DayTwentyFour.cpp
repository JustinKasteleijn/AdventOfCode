//
// Created by justi on 6/1/2023.
//

#include "DayTwentyFour.h"

namespace AdventOfCode {
    uint64_t DayTwentyFour::solve(const std::vector<std::string> &data, int groups) {
        std::vector<int> values;
        values.reserve(data.size());

        for(const std::string& line : data) {
            values.emplace_back(std::stoi(line));
        }

        uint64_t ret = std::numeric_limits<uint64_t>::max();

        int _sum = 0;
        int groupSum = 0;

        for (auto &n : values) {
            _sum += n;
        }

        groupSum = _sum / groups;

        std::vector<std::vector<int>> out;

        genCombinationSum<int>(values, groupSum, out);

        for (auto &s : out) {
            uint64_t sum = 1;

            for (auto &v : s) {
                sum *= v;
            }

            if (sum < ret) {
                ret = sum;
            }
        }

        return ret;
    }
} // AdventOfCode
