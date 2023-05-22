//
// Created by justi on 12/12/2022.
//

#include <vector>
#include "StringUtils.h"

std::pair<std::string, std::string>
StringUtils::split_string(const std::string &to_split, const std::string &delimiter) {
    std::size_t n = to_split.find(delimiter);
    return {to_split.substr(0, n), to_split.substr((n + delimiter.size()), to_split.length() - 1)};
}

std::vector<std::string> StringUtils::split_string(std::string s, char delimiter) {
    size_t pos;
    std::string token;
    std::vector<std::string> result;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        result.emplace_back(token);
        s.erase(0, pos + 1);
    }
    result.push_back(s);
    return std::move(result);
}
