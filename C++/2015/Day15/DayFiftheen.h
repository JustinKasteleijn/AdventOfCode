//
// Created by justi on 5/24/2023.
//

#ifndef ADVENTOFCODE_DAYFIFTHEEN_H
#define ADVENTOFCODE_DAYFIFTHEEN_H

#include <vector>
#include <string>
#include <numeric>

namespace AdventOfCode {

    class DayFiftheen {
    public:
        struct Ingredient {
            int capacity;
            int durability;
            int flavor;
            int texture;
            int calories;
        };

        struct Recipe {
            std::vector<int> quantities;

            static void build(const std::vector<Ingredient> &ingredients,
                              const std::vector<int> &quantities, Recipe &best,
                              int &best_score) {
                int current = std::accumulate(quantities.begin(), quantities.end(), 0);

                if (current < 100) {
                    if (quantities.size() < ingredients.size()) {
                        for (int i = 0; i <= 100 - current; ++i) {
                            auto new_quantities = quantities;
                            new_quantities.push_back(i);
                            build(ingredients, new_quantities, best, best_score);
                        }
                    }
                } else {
                    int score;
                    int c{0}, d{0}, f{0}, t{0}, cal{0};

                    for (size_t i = 0; i < quantities.size(); ++i) {
                        int q = quantities[i];
                        auto ing = ingredients[i];
                        c += q * ing.capacity;
                        d += q * ing.durability;
                        f += q * ing.flavor;
                        t += q * ing.texture;
                        cal += q * ing.calories;
                    }

                    c = std::max(0, c);
                    d = std::max(0, d);
                    f = std::max(0, f);
                    t = std::max(0, t);

                    score = c * d * f * t;

                    if (cal == 500 && score > best_score) {
                        best.quantities = quantities;
                        best_score = score;
                    }
                }
            }
        };

    public:
        static unsigned long parse(const std::vector<std::string> &data, bool part2);
    };

} // AdventOfCode
#endif //ADVENTOFCODE_DAYFIFTHEEN_H
