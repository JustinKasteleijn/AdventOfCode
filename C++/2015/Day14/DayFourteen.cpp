//
// Created by justi on 5/24/2023.
//

#include "DayFourteen.h"
#include <algorithm>
#include "../../StringUtils.h"

namespace AdventOfCode {
    int DayFourteen::parse(const std::vector<std::string> &data, int duration, bool part2) {
        std::vector<Reindeer> reindeer;
        for (const std::string &line: data) {
            std::vector<std::string> split = StringUtils::split_string(line, ' ');
            reindeer.emplace_back(Reindeer{
                    .name = split.front(),
                    .speed = std::stoi(split.at(3)),
                    .stamina = std::stoi(split.at(6)),
                    .rest_period = std::stoi(split.at(13)),
                    .remaining_resting_period = 0,
                    .remaining_stamina = std::stoi(split.at(6))
            });
        }

        std::map<std::string, int> distances;
        std::transform(reindeer.begin(), reindeer.end(), std::inserter(distances, distances.begin()),
                       [](const Reindeer &r) { return std::make_pair(r.name, 0); });

        std::map<std::string, int> scoring;
        std::transform(reindeer.begin(), reindeer.end(), std::inserter(scoring, scoring.begin()),
                       [](const Reindeer &r) { return std::make_pair(r.name, 0); });


        for (std::size_t i = 0; i <= duration; ++i) {
            for (Reindeer &r: reindeer) {
                if (r.remaining_stamina > 0) {
                    if (r.remaining_stamina == 1) {
                        r.remaining_resting_period = r.rest_period;
                    }
                    distances[r.name] += r.speed;
                    --r.remaining_stamina;
                } else if (r.remaining_resting_period > 0) {
                    if (r.remaining_resting_period == 1) {
                        r.remaining_stamina = r.stamina;
                    }
                    --r.remaining_resting_period;
                }
            }
            if (part2) {
                std::vector<std::string> best_reindeer = findKeysWithMaxValue(distances);
                for (const std::string &r: best_reindeer)
                    scoring[r] += 1;
            }
        }

        return part2 ? std::max_element(scoring.begin(), scoring.end(),
                                        [](const auto &pair1, const auto &pair2) {
                                            return pair1.second < pair2.second;
                                        })->second
                     : std::max_element(distances.begin(), distances.end(),
                                        [](const auto &pair1, const auto &pair2) {
                                            return pair1.second < pair2.second;
                                        })->second;
    }

    std::vector<std::string> DayFourteen::findKeysWithMaxValue(const std::map<std::string, int> &scoring) {
        std::vector<std::string> keysWithMaxValue;
        int maxValue = std::numeric_limits<int>::min();

        for (const auto& [name, score]: scoring) {
            if (score > maxValue) {
                maxValue = score;
                keysWithMaxValue.clear();
            }
            if (score == maxValue) {
                keysWithMaxValue.push_back(name);
            }
        }

        return keysWithMaxValue;
    }

} // AdventOfCode
