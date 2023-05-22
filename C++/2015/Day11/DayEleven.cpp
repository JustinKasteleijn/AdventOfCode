//
// Created by justi on 5/22/2023.
//

#include "DayEleven.h"
#include "reverser.h"

namespace AdventOfCode {
    std::string DayEleven::parse(const std::string &password, const bool part2) {
        std::string pw = password;
        return next(part2 ? next(pw) : pw);
    }

    char DayEleven::next_letter(char &c) {
        if (c == 'z') {
            c = 'a';
        } else {
            c = static_cast<char>(c + 1 + (c == 'h' || c == 'n' || c == 'k'));
        }
        return c;
    }

    bool DayEleven::passes(const std::string &pw) {
        bool hasTwo = false;
        bool hasThree = false;
        char previousChar = '\0';
        char currentChar = '\0';
        char lastChar = '\0';

        for (const char &c: pw) {
            if (!hasTwo && c == currentChar && c != lastChar) {
                if (lastChar != '\0') {
                    hasTwo = true;
                } else {
                    lastChar = c;
                }
            }
            hasThree = hasThree || ((previousChar + 1) == currentChar && (currentChar + 1) == c);
            previousChar = currentChar;
            currentChar = c;
        }

        return hasTwo && hasThree;
    }

    std::string &DayEleven::next(std::string &pw) {
        do {
            for (char &c: reverser<std::string>(pw)) {
                if (next_letter(c) != 'a') {
                    break;
                }
            }
        } while (!passes(pw));
        return pw;
    }
} // AdventOfCode
