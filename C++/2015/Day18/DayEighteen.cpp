//
// Created by justi on 5/30/2023.
//

#include <iostream>
#include <numeric>
#include "DayEighteen.h"

namespace AdventOfCode {
    Grid DayEighteen::parse(const std::vector<std::string> &data) {
        Grid grid(data.size(), std::vector<char>(data.size(), ' '));

        for (std::size_t i = 0; i < data.size(); ++i) {
            for (std::size_t j = 0; j < data.size(); ++j) {
                grid[i][j] = data[i][j];
            }
        }

        return std::move(grid);
    }

    int DayEighteen::solve(const std::vector<std::string> &data) {
        Grid grid = parse(data);
        turn_on_corners(grid);

        for (std::size_t iterations = 0; iterations < 100; ++iterations) {
            Grid grid_copy = grid;
            for (std::size_t i = 0; i < grid.size(); ++i) {
                for (std::size_t j = 0; j < grid[i].size(); ++j) {
                    char *current = &grid[i][j];
                    int on_adjacent = adjacent(grid_copy, static_cast<int>(i), static_cast<int>(j));
                    turn_on_corners(grid_copy);
                    turn_on_corners(grid);
                    if (get_state(grid_copy[i][j]) == ON) {
                        if (on_adjacent == 2 || on_adjacent == 3)
                            continue;

                        turn_off(*current);
                    } else {
                        if (on_adjacent != 3)
                            continue;

                        turn_on(*current);
                    }
                }
            }
        }

        return std::accumulate(grid.begin(), grid.end(), 0, [](int lhs, const std::vector<char> &row) {
            return std::accumulate(row.begin(), row.end(), lhs, [](int lhs, const char &current) {
                return lhs + (current == '#');
            });
        });
    }

    DayEighteen::Lights DayEighteen::get_state(const char &current) {
        return current == '#' ? ON : OFF;
    }

    int DayEighteen::adjacent(const Grid &grid, int i, int j) {
        int on = 0;

        std::size_t gridSize = grid.size();
        std::size_t rowSize = grid[i].size();

        for (std::size_t x = (i > 0) ? i - 1 : 0; x <= i + 1; ++x) {
            if (x >= gridSize)
                continue;

            for (std::size_t y = (j > 0) ? j - 1 : 0; y <= j + 1; ++y) {
                if (y >= rowSize || (x == i && y == j))
                    continue;

                if (get_state(grid[x][y]) == ON) {
                    ++on;
                }
                if (on > 3)
                    return on;
            }
        }
        return on;
    }

    void DayEighteen::turn_on_corners(Grid &grid) {
        std::vector<std::pair<int, int>> corners{
                {0,  0},
                {0,  99},
                {99, 0},
                {99, 99}
        };
        for (auto [x, y]: corners) {
            turn_on(grid[x][y]);
        }
    }
} // AdventOfCode
