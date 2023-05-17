//
// Created by justi on 12/12/2022.
//

#include "StringUtils.h"

std::pair<std::string, std::string>
StringUtils::split_string(const std::string &to_split, const std::string delimiter) {
    int n = to_split.find(delimiter);
    return {to_split.substr(0, n), to_split.substr(n, to_split.length() - 1)};
}
