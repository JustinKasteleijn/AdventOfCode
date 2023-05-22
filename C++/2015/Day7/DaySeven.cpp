//
// Created by justi on 5/20/2023.
//

#include <algorithm>
#include <iostream>
#include <queue>
#include "DaySeven.h"
#include "../../StringUtils.h"

namespace AdventOfCode {

    std::unordered_map<std::string, std::function<uint16_t(uint16_t x, uint16_t y)>> DaySeven::operations = {
            {"AND",    [](uint16_t x, uint16_t y) -> uint16_t { return (x & y); }},
            {"OR",     [](uint16_t x, uint16_t y) -> uint16_t { return (x | y); }},
            {"RSHIFT", [](uint16_t x, uint16_t y) -> uint16_t { return (x >> y); }},
            {"LSHIFT", [](uint16_t x, uint16_t y) -> uint16_t { return (x << y); }},
    };

    uint16_t DaySeven::parse(const std::vector<std::string> &data) {
        Wires wires;
        std::queue<std::string> instruction_queue;
        for (const std::string &line: data) {
            instruction_queue.emplace(line);
        }
        while (!instruction_queue.empty()) {
            auto [lhs, rhs] = StringUtils::split_string(instruction_queue.front(), "-> ");
            std::string output = std::move(rhs);

            std::vector<std::string> tokens = StringUtils::split_string(lhs, ' ');
            int16_t result = parse_instruction(tokens, wires);
            if (result != -1 && wires.find(output) == wires.end() && result != 0) {
                wires.insert({output, static_cast<uint16_t>(std::abs(result))});
            } else {
                instruction_queue.emplace(instruction_queue.front());
            }
            instruction_queue.pop();
        }
        for(const auto& [wire, value] : wires) {
            std::cout << wire << ":   " << value <<'\n';
        }
        return wires.at("a");
    }

    int16_t DaySeven::parse_instruction(const std::vector<std::string> &tokens, Wires &wires) {
        const std::size_t instruction_size = (tokens.size() - 1);
        if (instruction_size == 1) {
            const std::string &x = tokens.front();
            if (is_digit(x)) {
                return static_cast<int16_t>(std::stoi(x));
            } else if (wires.find(x) != wires.end()) {
                return static_cast<int16_t>(wires.at(x));
            }
        } else if (instruction_size == 2) {
            const std::string &x = tokens.at(1);
            if (is_digit(x)) {
                return static_cast<int16_t>(~std::stoi(x));
            } else if (wires.find(x) != wires.end()) {
                return static_cast<int16_t>(wires.at(x));
            }
        } else if (instruction_size == 3) {
            int16_t temp = 0;
            const std::string &x = tokens.front();
            const std::string &y = tokens.at(2);
            if (is_digit(x)) {
                temp = static_cast<int16_t>(std::stoi(x));
            } else if (wires.find(x) != wires.end()) {
                temp = static_cast<int16_t>(wires.at(x));
            } else {
                return -1;
            }

            if (is_digit(y)) {
                return static_cast<int16_t>(operations.at(tokens.at(1))(temp, static_cast<int16_t>(std::stoi(y))));
            } else if (wires.find(y) != wires.end()) {
                return static_cast<int16_t>(operations.at(tokens.at(1))(temp, static_cast<int16_t>(wires.at(y))));
            }
        }
        return -1;
    }

    bool DaySeven::is_digit(const std::string &digit) {
        return std::all_of(digit.begin(), digit.end(), [](const char &ch) { return std::isdigit(ch); });
    }

    uint16_t DaySeven::to_uint16t(const std::string &digit) {
        return static_cast<uint16_t>(std::abs(std::stoi(digit)));
    }
} // AdventOfCode
