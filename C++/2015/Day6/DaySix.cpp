//
// Created by justi on 5/17/2023.
//

#include <memory>
#include "DaySix.h"

namespace AdventOfCode {

    int DaySix::solve(const std::vector<std::string> &data) {
        std::vector<Instructions> instructions = parse(data);
        bool grid[1000][1000] = {{false}};

        int total = 0;
        for (Instructions instruction: instructions) {
            switch (instruction.first) {
                case TOGGLE:
                    for (std::size_t x = instruction.second.start.x; x <= instruction.second.end.x; ++x) {
                        for (std::size_t y = instruction.second.start.y; y <= instruction.second.end.y; ++y) {
                            grid[x][y] = !grid[x][y];
                        }
                    }
                    break;
                case ON:
                    for (std::size_t x = instruction.second.start.x; x <= instruction.second.end.x; ++x) {
                        for (std::size_t y = instruction.second.start.y; y <= instruction.second.end.y; ++y) {
                            grid[x][y] = true;
                        }
                    }
                    break;
                case OFF:
                    for (std::size_t x = instruction.second.start.x; x <= instruction.second.end.x; ++x) {
                        for (std::size_t y = instruction.second.start.y; y <= instruction.second.end.y; ++y) {
                            grid[x][y] = false;
                        }
                    }
                    break;
                default:
                    return -1;

            }
        }
        for (const auto &x: grid) {
            for (auto y: x) {
                total += y;
            }
        }
        return total;
    }

    unsigned long DaySix::solve2(const std::vector<std::string> &data) {
        std::vector<Instructions> instructions = parse(data);

        std::unique_ptr<std::unique_ptr<int[]>[]> grid = std::make_unique<std::unique_ptr<int[]>[]>(1000);

        for (int i = 0; i < 1000; ++i) {
            grid[i] = std::make_unique<int[]>(1000);
            for (int j = 0; j < 1000; ++j) {
                grid[i][j] = 0;
            }
        }

        unsigned long total = 0;
        for (Instructions instruction: instructions) {
            switch (instruction.first) {
                case TOGGLE:
                    for (std::size_t x = instruction.second.start.x; x <= instruction.second.end.x; ++x) {
                        for (std::size_t y = instruction.second.start.y; y <= instruction.second.end.y; ++y) {
                            grid[x][y] += 2;
                        }
                    }
                    break;
                case ON:
                    for (std::size_t x = instruction.second.start.x; x <= instruction.second.end.x; ++x) {
                        for (std::size_t y = instruction.second.start.y; y <= instruction.second.end.y; ++y) {
                            grid[x][y] += 1;
                        }
                    }
                    break;
                case OFF:
                    for (std::size_t x = instruction.second.start.x; x <= instruction.second.end.x; ++x) {
                        for (std::size_t y = instruction.second.start.y; y <= instruction.second.end.y; ++y) {
                            if (grid[x][y] - 1 >= 0) grid[x][y] -= 1;
                            else grid[x][y] = 0;
                        }
                    }
                    break;
                default:
                    return -1;

            }
        }
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 1000; ++j) {
                total += grid[i][j];
            }
        }
        return total;
    }

    Coordinate DaySix::getCoordinates(const std::string &line) {
        int i = (int) line.find(',');
        Coordinate coordinate{};
        coordinate.x = std::stoi(line.substr(0, i));
        coordinate.y = std::stoi(line.substr(i + 1, line.find(' ')));
        return coordinate;
    }

    std::vector<Instructions> DaySix::parse(const std::vector<std::string> &data) {
        std::vector<Instructions> result;
        Event event;
        std::string s_event;
        Coordinates coordinates{};
        for (std::string line: data) {
            int i = (int) line.find(' ');
            s_event = line.substr(0, i);
            if (s_event == "toggle") {
                event = TOGGLE;
                line.erase(0, i + 1);
            } else {
                line.erase(0, i + 1);
                i = (int) line.find(' ');
                s_event = line.substr(0, i);
                if (s_event == "off") event = OFF;
                else if (s_event == "on") event = ON;
                line.erase(0, i + 1);
            }

            coordinates.start = getCoordinates(line);

            line.erase(0, line.find('g') + 3);

            coordinates.end = getCoordinates(line);
            result.emplace_back(event, coordinates);
        }
        return result;
    }
} // AdventOfCode
