//
// Created by justi on 5/22/2023.
//

#include <regex>
#include <iostream>
#include "DayNine.h"
#include "../../StringUtils.h"

namespace AdventOfCode {

    int DayNine::parse(const std::vector<std::string> &data) {
        Distances distances;

        for (const std::string &line: data) {
            std::smatch m;
            std::regex_match(line, m, std::regex("(.*) to (.*) = (.*)"));
            distances[m[1]][m[2]] = distances[m[2]][m[1]] = std::stoi(m[3]);
        }

        std::vector<std::string> cities(distances.size());
        std::transform(distances.begin(), distances.end(), cities.begin(),
                       [](const std::pair<const std::string, std::map<std::string, int>> &p) { return p.first; });

        int min_distance = INT_MAX;
        do {
            int curr_dist = 0;
            for (auto it = cities.begin(); it != (cities.end() - 1); ++it) {
                curr_dist += distances[*it][*(it + 1)];
            }

            min_distance = std::min(curr_dist, min_distance);
        } while (std::next_permutation(cities.begin(), cities.end()));
        return min_distance;
    }

    int DayNine::parse2(const std::vector<std::string> &data) {
        Distances distances;

        for (const std::string &line: data) {
            std::smatch m;
            std::regex_match(line, m, std::regex("(.*) to (.*) = (.*)"));
            distances[m[1]][m[2]] = distances[m[2]][m[1]] = std::stoi(m[3]);
        }

        std::vector<std::string> cities(distances.size());
        std::transform(distances.begin(), distances.end(), cities.begin(), [](auto p) { return p.first; });

        int max_distance = INT_MIN;
        do {
            int curr_dist = 0;
            for (auto it = cities.begin(); it != (cities.end() - 1); ++it)
                curr_dist += distances[*it][*(it + 1)];

            max_distance = std::max(curr_dist, max_distance);
        } while (std::next_permutation(cities.begin(), cities.end()));
        return max_distance;
    }
} // AdventOfCode
