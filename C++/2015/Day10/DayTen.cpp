//
// Created by justi on 5/22/2023.
//

#include <iostream>
#include "DayTen.h"

namespace AdventOfCode {
    int DayTen::parse(const std::vector<std::string> &data, int process) {
        std::string result;
        for (const std::string &line: data) {
            result = line;
            for (std::size_t i = 0; i < process; ++i) {
                std::vector<Occurrences> occurrences = get_occurrences(result);
                result = parse_occurrences(occurrences);
            }
        }
        return static_cast<int>(result.size());
    }

    std::vector<DayTen::Occurrences> DayTen::get_occurrences(const std::string &line) {
        char predicate;
        int count = 1;
        std::vector<Occurrences> occurrences;
        for (std::size_t i = 0; i < line.length(); ++i) {
            predicate = line[i];
            if (predicate == line[i + 1]) {
                count++;
            } else {
                occurrences.emplace_back(Occurrences{
                        .occurrences = std::to_string(count),
                        .digit = std::string(1, predicate)
                });
                count = 1;
            }
        }
        return occurrences;
    }

    std::string DayTen::parse_occurrences(const std::vector<Occurrences> &occurrences) {
        std::string result;
        for (const Occurrences &occurrence: occurrences) {
            result += (occurrence.occurrences + occurrence.digit);
        }
        return result;
    }
} // AdventOfCode
