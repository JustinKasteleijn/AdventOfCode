//
// Created by justi on 12/7/2022.
//

#ifndef ADVENTOFCODE_ADVENTTHREE_H
#define ADVENTOFCODE_ADVENTTHREE_H


#include <unordered_map>
#include <vector>
#include <bits/unordered_map.h>

class AdventThree {
public:
    const std::unordered_map<char, int> scores;

    AdventThree();

    static std::pair<std::string, std::string> split_strings(const std::string& to_split);
    static char find_first_equal_character(const std::pair<std::string, std::string>& data);
    int get_sum_of_rucksack(const std::vector<std::string>& data);
    int score(const std::vector<char>& result);

    int get_sum_of_rucksack_group(const std::vector<std::string>& data);
    static char find_equal_in_group_of_rucksack(const std::vector<std::string>& lines);
};


#endif //ADVENTOFCODE_ADVENTTHREE_H
