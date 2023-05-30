//
// Created by justi on 5/30/2023.
//

#include <algorithm>
#include <iostream>
#include <functional>
#include "DaySeventeen.h"

namespace AdventOfCode {

    int DaySeventeen::findCombinations(const std::vector<int> &numbers, int target) {
        int n = numbers.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));

        // Base case: If the target is 0, there is one combination (empty set).
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= target; ++j) {
                // Exclude the current number.
                dp[i][j] = dp[i + 1][j];

                // Include the current number if it does not exceed the target.
                if (j >= numbers[i]) {
                    dp[i][j] += dp[i + 1][j - numbers[i]];
                }
            }
        }

        return dp[0][target];
    }

    int DaySeventeen::_part2(std::vector<int> containers, std::vector<int> &sizes, int goal, int values_in_goal = 0) {
        if (containers.size() == 0)
            return 0;

        int first = containers[0];
        std::vector<int> remain;
        remain.assign(containers.begin() + 1, containers.end());

        int with_first;
        if (first > goal)
            with_first = 0;
        else if (first == goal) {
            sizes.push_back(values_in_goal + 1);
            with_first = 1;
        } else {
            with_first = _part2(remain, sizes, goal - first, values_in_goal + 1);
        }

        return with_first + _part2(remain, sizes, goal, values_in_goal);
    }


    int DaySeventeen::parse(const std::vector<std::string> &data, const int target, bool part2) {
        std::vector<int> numbers;
        std::vector<int> sizes;
        numbers.reserve(data.size());
        for (const std::string &to_int: data) {
            numbers.emplace_back(std::stoi(to_int));
        }

        return part2 ? _count(_part2(numbers, sizes, target), sizes) : findCombinations(numbers, target);
    }

    int DaySeventeen::_count(int part2, std::vector<int> &sizes) {
        std::sort(sizes.begin(), sizes.end());

        // find the minimum size
        int min = sizes[0];
        int c = 0;

        for (auto s: sizes)
            if (min == s) ++c; else if (s > min) break;

        return c;
    }

}
