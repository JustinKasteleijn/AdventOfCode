//
// Created by justi on 5/16/2023.
//
#include <algorithm>
#include <cstring>
#include "DayFive.h"

namespace AdventOfCode {
    int DayFive::solve(const std::vector<std::string> &data) {
        constexpr char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
        const std::vector<std::string> bad_words{"ab", "cd", "pq", "xy"};
        int nice_words = 0;

        for (const std::string &line: data) {
            char previous = '\0';
            bool twice_in_a_row = false;
            int vowel_count = 0;
            for (const char &ch: line) {
                std::string val;
                val.push_back(previous);
                val.push_back(ch);

                if (std::find(bad_words.begin(), bad_words.end(), val) != bad_words.end()) {
                    twice_in_a_row = false;
                    break;
                }

                if (previous == ch) {
                    twice_in_a_row = true;
                }

                for (const char &vowel: vowels) {
                    if (ch == vowel) {
                        ++vowel_count;
                        continue;
                    }
                }
                previous = ch;
            }
            nice_words += (twice_in_a_row && vowel_count >= 3);
        }

        return nice_words;
    }

    int DayFive::solve2(const std::vector<std::string> &data) {
        int nice_words = 0;

        for (const std::string &_line: data) {
            const char *line = _line.data();
            int pattern_1 = 0;
            int pattern_2 = 0;
            int pairs['z' - 'a' + 1]['z' - 'a' + 1];
            int *first_pair;

            std::memset(pairs, -1, sizeof pairs); /* zero the pairs array */

            int i = 0;
            line++;
            while (*line) {
                first_pair = &pairs[*(line - 1) - 'a'][*line - 'a'];

                /* It contains a pair of any two letters that appears at least twice in the string without overlapping */
                if (*first_pair == -1) {
                    *first_pair = i;
                } else if (*first_pair != -1 && *first_pair < (i - 1)) {
                    pattern_2 = 1;
                }

                /* It contains at least one letter which repeats with exactly one letter between them */
                if (i >= 2 && *(line - 2) == *line) {
                    pattern_1 = 1;
                }

                line++;
                i++;
            }
            first_pair = nullptr;
            delete first_pair;

            line = nullptr;
            delete line;
            nice_words += (pattern_1 && pattern_2);
        }
        return nice_words;
    }
} // AdventOfCode
