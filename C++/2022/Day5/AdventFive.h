//
// Created by justi on 12/12/2022.
//

#ifndef ADVENTOFCODE_ADVENTFIVE_H
#define ADVENTOFCODE_ADVENTFIVE_H


#include <string>
#include <vector>
#include <stack>

class AdventFive {
public:
    std::string parse(const std::vector<std::string> &data);

    static std::vector<std::stack<char>> parse_stacks(const std::string& stacks_as_string);

    std::vector<int> parse_moves(std::string &moves_as_string);

    void doMoves(std::vector<std::stack<char>>& stacks, const std::vector<int> &moves);

    static std::stack<char> reverse(std::stack<char> stack);
};


#endif //ADVENTOFCODE_ADVENTFIVE_H
