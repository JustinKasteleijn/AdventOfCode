//
// Created by justi on 5/20/2023.
//

#ifndef ADVENTOFCODE_DAYSEVEN_H
#define ADVENTOFCODE_DAYSEVEN_H

#include <map>
#include <unordered_map>
#include <functional>
#include <vector>

namespace AdventOfCode {
    class DaySeven {
    public:
        static uint16_t parse(const std::vector<std::string> &data);

    private:
        using Wires = std::map<std::string, uint16_t>;

        static int16_t parse_instruction(const std::vector<std::string> &tokens, Wires& wires);

        inline static bool is_digit(const std::string &digit);

        inline static uint16_t to_uint16t(const std::string &digit);

        static std::unordered_map<std::string, std::function<uint16_t(uint16_t, uint16_t)>> operations;
    };
} // AdventOfCode

#endif //ADVENTOFCODE_DAYSEVEN_H
