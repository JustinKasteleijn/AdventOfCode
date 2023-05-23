//
// Created by justi on 5/23/2023.
//

#include "DayTwelve.h"
#include <cassert>
#include <cctype>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <variant>
#include <numeric>

namespace AdventOfCode {
    unsigned long DayTwelve::parse(const std::string &data) {
        unsigned long total = 0;
        std::smatch matches;
        std::regex digitRegex("-?\\d+");

        std::string::const_iterator searchStart(data.cbegin());
        while (std::regex_search(searchStart, data.cend(), matches, digitRegex)) {
            for (const auto &match: matches) {
                total += std::stoi(match);
            }
            searchStart = matches.suffix().first;
        }
        return total;
    }

    int DayTwelve::_parse(std::string const &s, std::string::size_type &pos) {
        int result = 0;
        bool ignore = false;
        std::size_t len = 0;
        std::string v{};

        while (pos < s.size()) {
            switch (s[pos]) {
                case '{':
                case '[':
                    ++pos;
                    result += _parse(s, pos);
                    break;
                case '}':
                    ++pos;
                    return ignore ? 0 : result;
                case ']':
                    ++pos;
                    return result;
                case '"':
                    ++pos;
                    len = s.find('"', pos);
                    assert(len != std::string::npos);
                    v = s.substr(pos, len - pos);
                    if (v == "red") {
                        ignore = true;
                    }
                    pos = len + 1;
                    break;
                default:
                    if (std::isdigit(s[pos]) || s[pos] == '-') {
                        result += std::stoi(s.substr(pos), &len);
                        pos += len;
                    } else {
                        assert(s[pos] == ',' || s[pos] == ':');
                        ++pos;
                    }
                    break;
            }
        }
        return result;
    }

    int DayTwelve::parse_numbers(std::string const &s) {
        std::string::size_type pos = 0;
        int result = _parse(s, pos);
        assert(pos == s.size());
        return result;
    }

    unsigned long DayTwelve::parse2(const std::vector<std::string> &data) {
        return std::accumulate(data.begin(), data.end(), 0UL,
                               [](unsigned long acc, const std::string &line) {
                                   return acc + parse_numbers(line);
                               }
        );
    }
} // AdventOfCode
