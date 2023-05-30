//
// Created by justi on 5/30/2023.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "DaySixteen.h"
#include "../../StringUtils.h"

namespace AdventOfCode {
    std::unordered_map<std::string, int> DaySixteen::real_sue = {
            {"children",    3},
            {"cats",        7},
            {"samoyeds",    2},
            {"pomeranians", 3},
            {"akitas",      0},
            {"vizslas",     0},
            {"goldfish",    5},
            {"trees",       3},
            {"cars",        2},
            {"perfumes",    1},
    };

    int DaySixteen::parse(std::ifstream &input, bool part2) {
        int result = 0;

        std::string line;
        while (std::getline(input, line)) {
            std::istringstream ss(line);

            bool match = true;
            int32_t sueNum = -1;

            std::string key, value;
            while (match && (ss >> key >> value)) {
                std::cout << key << ": " << value << '\n';

                if (key == "Sue") {
                    sueNum = std::stoi(value);
                    continue;
                }

                key.pop_back(); // remove ending ':'

                if (part2) {
                    int32_t num = std::stoi(value);

                    if (key == "cats" || key == "trees") {
                        match = (num > real_sue[key]);
                    } else if (key == "pomeranians" || key == "goldfish") {
                        match = (num < real_sue[key]);
                    } else {
                        match = (num == real_sue[key]);
                    }
                } else {
                    if (real_sue[key] != std::stoi(value)) {
                        match = false;
                        break;
                    }
                }
            }

            if (match) {
                result = sueNum;
                break;
            }
        }
        return result;
    }
} // AdventOfCode
