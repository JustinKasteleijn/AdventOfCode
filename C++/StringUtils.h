//
// Created by justi on 12/12/2022.
//

#ifndef ADVENTOFCODE_STRINGUTILS_H
#define ADVENTOFCODE_STRINGUTILS_H


#include <string>

class StringUtils {
public:
    static std::pair<std::string, std::string> split_string(const std::string &to_split, const std::string &delimiter);

    static std::vector<std::string> split_string(std::string s, char delimiter);
};


#endif //ADVENTOFCODE_STRINGUTILS_H
