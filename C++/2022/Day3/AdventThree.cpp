//
// Created by justi on 12/7/2022.
//

#include "AdventThree.h"

#include <utility>
#include <set>

int AdventThree::get_sum_of_rucksack(const std::vector<std::string> &data) {
    std::vector<char> result;
    result.reserve(data.size());
    for (const std::string &line : data) {
        result.push_back(
                find_first_equal_character(split_strings(line))
        );
    }
    return score(result);
}

int AdventThree::get_sum_of_rucksack_group(const std::vector<std::string> &data) {
    std::vector<char> result;
    std::vector<std::string> lines;
    result.reserve(data.size());
    for (const std::string &line : data) {
        lines.push_back(line);
        if (lines.size() == 3) {
            result.push_back(
                    find_equal_in_group_of_rucksack(lines)
            );
            lines.clear();
        }
    }
    return score(result);
}

char AdventThree::find_equal_in_group_of_rucksack(const std::vector<std::string> &lines) {
    std::set<char> result;
    for (const char &c : lines.at(0)) {
        result.insert(c);
    }

    for (const char &c : lines.at(1)) {
        if (result.find(c) != result.end()) {
            for (const char &c2 : lines.at(2)) {
                if (c2 == c) {
                    return c;
                }
            }
        }
    }
    return ' ';
}

std::pair<std::string, std::string> AdventThree::split_strings(const std::string &to_split) {
    std::string half = to_split.substr(0, to_split.length() / 2);
    std::string otherHalf = to_split.substr(to_split.length() / 2);
    return {half, otherHalf};
}

char AdventThree::find_first_equal_character(const std::pair<std::string, std::string> &data) {
    for (const char &c : data.first) {
        if (data.second.find(c) != -1)
            return c;
    }
    return ' ';
}

int AdventThree::score(const std::vector<char> &result) {
    int sum = 0;
    for (const char &c : result) {
        sum += scores.at(c);
    }
    return sum;
}

AdventThree::AdventThree() : scores(
        {
                {'a', 1},
                {'b', 2},
                {'c', 3},
                {'d', 4},
                {'e', 5},
                {'f', 6},
                {'g', 7},
                {'h', 8},
                {'i', 9},
                {'j', 10},
                {'k', 11},
                {'l', 12},
                {'m', 13},
                {'n', 14},
                {'o', 15},
                {'p', 16},
                {'q', 17},
                {'r', 18},
                {'s', 19},
                {'t', 20},
                {'u', 21},
                {'v', 22},
                {'w', 23},
                {'x', 24},
                {'y', 25},
                {'z', 26},
                {'A', 27},
                {'B', 28},
                {'C', 29},
                {'D', 30},
                {'E', 31},
                {'F', 32},
                {'G', 33},
                {'H', 34},
                {'I', 35},
                {'J', 36},
                {'K', 37},
                {'L', 38},
                {'M', 39},
                {'N', 40},
                {'O', 41},
                {'P', 42},
                {'Q', 43},
                {'R', 44},
                {'S', 45},
                {'T', 46},
                {'U', 47},
                {'V', 48},
                {'W', 49},
                {'X', 50},
                {'Y', 51},
                {'Z', 52}
        }
) {}


