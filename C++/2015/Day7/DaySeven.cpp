//
// Created by justi on 5/17/2023.
//

#include "DaySeven.h"
#include "../../StringUtils.h"
#include <string>
#include <iostream>
#include <unordered_map>

namespace AdventOfCode {

    std::vector<Action> DaySeven::parse(const std::vector<std::string> &data) {
        std::vector<Action> result;
        result.reserve(300);
        for (const std::string &line: data) {
            std::vector<std::string> split = StringUtils::split_string(line, ' ');
            if (line.find("AND") != std::string::npos) {
                result.emplace_back(
                        Action{
                                .command = AND,
                                .from_address_x = {split.front()},
                                .from_address_y {split[2]},
                                .to_address = {split.back()}
                        }
                );
            } else if (line.find("OR") != std::string::npos) {
                result.emplace_back(
                        Action{
                                .command = OR,
                                .from_address_x = {split.front()},
                                .from_address_y {split[2]},
                                .to_address = {split.back()}
                        }
                );
            } else if (line.find("LSHIFT") != std::string::npos) {
                result.emplace_back(
                        Action{
                                .command = LSHIFT,
                                .from_address_x = {split.front()},
                                .from_address_y {.value = static_cast<uint16_t>(std::stoi(split[2]))},
                                .to_address = {split.back()}
                        }
                );
            } else if (line.find("RSHIFT") != std::string::npos) {
                result.emplace_back(
                        Action{
                                .command = RSHIFT,
                                .from_address_x = {split.front()},
                                .from_address_y {.value = static_cast<uint16_t>(std::stoi(split[2]))},
                                .to_address = {split.back()}
                        }
                );
            } else if (line.find("NOT") != std::string::npos) {
                result.emplace_back(
                        Action{
                                .command = NOT,
                                .from_address_x = {split[1]},
                                .to_address = {split[3]}
                        }
                );
            } else {
                result.emplace_back(
                        Action{
                                .command = WRITE,
                                .to_address = {.name = split[2], .value = static_cast<uint16_t>(std::stoi(
                                        split.front()))}
                        }
                );
            }
        }
        return result;
    }

    int DaySeven::solve(const std::vector<Action> &assembly) {
        std::unordered_map<std::string, uint16_t> wires;
        wires.reserve(200);

        for (const Action &task: assembly) {
            switch (task.command) {
                case WRITE:

                    break;
                case AND:
                    break;
                case OR:
                    break;
                case LSHIFT:
                    break;
                case RSHIFT:
                    break;
                case NOT:
                    break;
            }
        }
    }
}
