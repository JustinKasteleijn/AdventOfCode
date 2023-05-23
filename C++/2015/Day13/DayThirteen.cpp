//
// Created by justi on 5/23/2023.
//

#include <algorithm>
#include <iostream>
#include <regex>
#include "DayThirteen.h"
#include "../../StringUtils.h"

namespace AdventOfCode {
    int DayThirteen::parse(const std::vector<std::string> &data, bool part2) {
        Happiness happiness;

        for (const std::string &line: data) {
            std::smatch m;
            std::regex_match(line, m, std::regex("(.*) would (.*?) (.*?) .* (.*)\\."));
            happiness[m[1]][m[4]] = (m[2] == "lose" ? -1 : 1) * std::stoi(m[3]);
            if (part2) happiness[m[1]]["Me"] = happiness["Me"][m[4]] = 0;
        }

        std::vector<std::string> people(happiness.size());
        std::transform(happiness.begin(), happiness.end(), people.begin(), [](auto p) { return p.first; });

        int max_happiness = 0;
        do {
            int current_happiness = (happiness[*(people.end() - 1)][*people.begin()] +
                                     happiness[*people.begin()][*(people.end() - 1)]);

            for (auto it = people.begin(); it != (people.end() - 1); ++it)
                current_happiness += (happiness[*it][*(it + 1)] + happiness[*(it + 1)][*it]);

            max_happiness = std::max(current_happiness, max_happiness);
        } while (std::next_permutation(people.begin(), people.end()));


        return max_happiness;
    }
} // AdventOfCode
