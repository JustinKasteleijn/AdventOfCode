//
// Created by justi on 5/22/2023.
//

#include "DayEight.h"

namespace AdventOfCode {

    int DayEight::parse(const std::vector<std::string> &data) {
        unsigned long total = 0;
        unsigned long size = 0;
        for (const std::string &line: data) {
            size += line.length();
            total += character_count2(line);
        }
        return std::abs(static_cast<int>(size - total));
    }

    int DayEight::character_count(const std::string &line) {
        int characterCount = 0;;
        std::size_t i = 0;
        while (i < line.length()) {
            char currentCharacter = (line[i]);
            if (currentCharacter == '\\' && i < strLen - 1) {
                if ((line[i + 1]) == '\\' || (line[i + 1]) == '\"') {
                    i += 2;
                } else if ((line[i + 1]) == 'x') {
                    i += 4;
                }
            } else {
                i++;
            }
            characterCount++;
        }
        return characterCount - 2;
    }

    int DayEight::character_count2(const std::string &line) {
        int characterCount = 0;
        for (char currentChar: line) {
            if (currentChar == '\\' || currentChar == '\"') {
                characterCount += 2;
            } else {
                characterCount++;
            }
        }

        return characterCount + 2;
    }
} // AdventOfCode
