//
// Created by justi on 5/24/2023.
//

#include <memory>
#include <iostream>
#include <algorithm>
#include "DayFiftheen.h"
#include "../../StringUtils.h"

namespace AdventOfCode {

    unsigned long DayFiftheen::parse(const std::vector<std::string> &data, bool part2) {
        std::vector<Ingredient> ingredients;

        for (const std::string &line: data) {
            std::string commas(line.size(), '0');
            commas.erase(std::remove_copy(line.begin(), line.end(), commas.begin(), ','), commas.end());
            std::vector<std::string> split = StringUtils::split_string(commas, ' ');
            ingredients.emplace_back(Ingredient{
                                             .capacity = std::stoi(split.at(2)),
                                             .durability = std::stoi(split.at(4)),
                                             .flavor = std::stoi(split.at(6)),
                                             .texture = std::stoi(split.at(8)),
                                             .calories = std::stoi(split.at(10))
                                     }

            );
        }

        const int TEASPOONS = 100;
        const int TARGETCALORIES = 500;

        int bestCookie = 0, best500 = 0, thiscookie = 0;
        int cap, dur, fla, tex, cal;
        // We know that there are 4 ingredients so we can limit the number of for... loops
        for (std::size_t i = 0; i <= TEASPOONS; i++) {
            for (std::size_t j = 0; j <= TEASPOONS && i + j <= TEASPOONS; j++) {
                for (std::size_t k = 0; k <= TEASPOONS && i + j + k <= TEASPOONS; k++) {
                    int l = static_cast<int>(TEASPOONS - i - j - k);

                    // Calculate cookie properties
                    cap = static_cast<int>((i * ingredients[0].capacity) + (j * ingredients[1].capacity) +
                                           (k * ingredients[2].capacity) +
                                           (l * ingredients[3].capacity));
                    dur = static_cast<int>((i * ingredients[0].durability) + (j * ingredients[1].durability) +
                                           (k * ingredients[2].durability) + (l * ingredients[3].durability));
                    fla = static_cast<int>((i * ingredients[0].flavor) + (j * ingredients[1].flavor) +
                                           (k * ingredients[2].flavor) +
                                           (l * ingredients[3].flavor));
                    tex = static_cast<int>((i * ingredients[0].texture) + (j * ingredients[1].texture) +
                                           (k * ingredients[2].texture) +
                                           (l * ingredients[3].texture));
                    cal = static_cast<int>((i * ingredients[0].calories) + (j * ingredients[1].calories) +
                                           (k * ingredients[2].calories) + (l * ingredients[3].calories));

                    thiscookie = (cap > 0 ? cap : 0)
                                 * (dur > 0 ? dur : 0)
                                 * (fla > 0 ? fla : 0)
                                 * (tex > 0 ? tex : 0);

                    // Part 1
                    if (thiscookie > bestCookie) {
                        bestCookie = thiscookie;
                    }
                    if (cal == TARGETCALORIES && thiscookie > best500) {
                        best500 = thiscookie;
                    }
                }
            }
        }
        return part2 ? best500 : bestCookie;
    }
}// AdventOfCode
