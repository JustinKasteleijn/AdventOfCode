//
// Created by justi on 12/7/2022.
//

#include "AdventFour.h"

int AdventFour::get_overlapping_pairs(const std::vector<std::string> &data) {
    int count = 0;
    for (const std::string &pairs : data) {
        if (overlaps_partially(pairs)) {
            count++;
        }
    }
    return count;
}

bool AdventFour::overlaps_fully(const std::string &pairs) {
    std::vector<std::pair<int, int>> pairs_as_numbers = separate_pairs(pairs);
    return (pairs_as_numbers.at(0).first <= pairs_as_numbers.at(1).first
            && pairs_as_numbers.at(0).second >= pairs_as_numbers.at(1).second)
           ||
           (pairs_as_numbers.at(0).first >= pairs_as_numbers.at(1).first
            && pairs_as_numbers.at(0).second <= pairs_as_numbers.at(1).second);
}

std::vector<std::pair<int, int>> AdventFour::separate_pairs(const std::string &pairs) {
    std::string s_first_pair = pairs.substr(0, pairs.find(','));
    std::string s_second_pair = pairs.substr(pairs.find(',') + 1, pairs.find('\n'));
    std::pair<int, int> first_pair = {std::stoi(s_first_pair.substr(0, s_first_pair.find('-'))), std::stoi(
            s_first_pair.substr(s_first_pair.find('-') + 1, s_first_pair.find('\n')))};
    std::pair<int, int> second_pair = {std::stoi(s_second_pair.substr(0, s_second_pair.find('-'))), std::stoi(
            s_second_pair.substr(s_second_pair.find('-') + 1, s_first_pair.find('\n')))};
    return {first_pair, second_pair};
}

bool AdventFour::overlaps_partially(const std::string &pairs) {
    std::vector<std::pair<int, int>> pairs_as_numbers = separate_pairs(pairs);
    return inRange(pairs_as_numbers.at(0).first, pairs_as_numbers.at(0).second, pairs_as_numbers.at(1).first) ||
           inRange(pairs_as_numbers.at(0).first, pairs_as_numbers.at(0).second, pairs_as_numbers.at(1).second)
           ||
           inRange(pairs_as_numbers.at(1).first, pairs_as_numbers.at(1).second, pairs_as_numbers.at(0).first) ||
           inRange(pairs_as_numbers.at(1).first, pairs_as_numbers.at(1).second, pairs_as_numbers.at(0).second);
}

bool AdventFour::inRange(const int low, const int high, const int x) {
    return (low <= x && x <= high);
}
