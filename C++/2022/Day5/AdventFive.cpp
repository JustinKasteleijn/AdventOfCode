//
// Created by justi on 12/12/2022.
//

#include "AdventFive.h"
#include "../../StringUtils.h"

std::string AdventFive::parse(const std::vector<std::string> &data) {
    std::string all;
    for (const std::string &line: data) {
        all += line + '\n';
    }
    std::pair<std::string, std::string> stacks_and_moves = StringUtils::split_string(all, "move");
    std::vector<std::stack<char>> stacks = parse_stacks(stacks_and_moves.first);
    std::vector<int> moves = parse_moves(stacks_and_moves.second);

    std::vector<std::stack<char>> reversed;
    int size = std::stoi(
            stacks_and_moves.first.substr(stacks_and_moves.first.length() - 3, stacks_and_moves.first.length() - 2));
    reversed.reserve(size);
    for (int i = 0; i < size; ++i) {
        reversed.emplace_back();
    }

    for (int i = 0; i < size; ++i) {
        reversed.at(i) = reverse(stacks[i]);
    }

    doMoves(reversed, moves);
    std::string result;
    for (std::stack<char> stack: reversed) {
        char c = stack.top();
        result += c;
    }
    return result;
}

std::vector<std::stack<char>> AdventFive::parse_stacks(const std::string &stacks_as_string) {
    int size = std::stoi(stacks_as_string.substr(stacks_as_string.length() - 3, stacks_as_string.length() - 2));

    std::vector<std::stack<char>> stacks;
    stacks.reserve(size);
    for (int i = 0; i < size; ++i) {
        stacks.emplace_back();
    }

    int count = 0;
    int row = 0;
    for (int i = 0; i < stacks_as_string.size(); ++i) {
        char c = stacks_as_string.at(i);
        if (c == '[') {
            int pos = count / 3;
            c = stacks_as_string[i + 1];
            if (row == 0 && pos > 4) {
                --pos;
            }
            stacks.at(pos).push(c);
        } else if (c == '\n') {
            row++;
            count = 0;
        } else {
            ++count;
        }
    }
    return stacks;
}

std::vector<int> AdventFive::parse_moves(std::string &moves) {
    std::vector<int> result{};
    while (!moves.empty()) {
        int temp = moves.find("move");
        int amount = std::stoi(moves.substr(temp + 4, temp + 6));

        temp = moves.find("from");
        int from = std::stoi(moves.substr(temp + 4, temp + 5));

        temp = moves.find("to");
        int to = std::stoi(moves.substr(temp + 3, temp + 4));

        result.push_back(amount);
        result.push_back(from);
        result.push_back(to);

        moves.erase(0, temp + 5);
    }
    return result;
}

void AdventFive::doMoves(std::vector<std::stack<char>> &stacks, const std::vector<int> &moves) {
    for (int i = 0; i < moves.size(); i += 3) {
        std::stack<char> &from = stacks.at(moves.at((i + 1)) - 1);
        std::stack<char> &to = stacks.at(moves.at((i + 2)) - 1);

        int size = moves.at(i);
        if (size > 1) {
            std::stack<char> reverse;
            for (int j = 0; j < size; ++j) {
                reverse.push(from.top());
                from.pop();
            }
            if (!reverse.empty()) {
                for (int x = 0; x < size; ++x) {
                    char temp = reverse.top();
                    reverse.pop();
                    to.push(temp);
                }
            }
        } else {
            for (int j = 0; j < size; j++) {
                if (!from.empty()) {
                    char temp = from.top();
                    from.pop();
                    to.push(temp);
                }
            }
        }
    }
}

std::stack<char> AdventFive::reverse(std::stack<char> orig) {
    std::stack<char> result;
    while (!orig.empty()) {
        result.push(orig.top());
        orig.pop();
    }
    return result;
}
