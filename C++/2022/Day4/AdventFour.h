//
// Created by justi on 12/7/2022.
//

#ifndef ADVENTOFCODE_ADVENTFOUR_H
#define ADVENTOFCODE_ADVENTFOUR_H


#include <string>
#include <vector>

class AdventFour {
public:
    int get_overlapping_pairs(const std::vector<std::string>& data);

    static bool overlaps_fully(const std::string &pairs);
    static bool overlaps_partially(const std::string &pairs);
    static bool inRange(const int low, const int high, const int x);

    static std::vector<std::pair<int, int>> separate_pairs(const std::string &pairs);
};


#endif //ADVENTOFCODE_ADVENTFOUR_H
