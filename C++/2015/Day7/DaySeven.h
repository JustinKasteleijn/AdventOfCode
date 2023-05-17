//
// Created by justi on 5/17/2023.
//

#ifndef ADVENTOFCODE_DAYSEVEN_H
#define ADVENTOFCODE_DAYSEVEN_H

#include <string>
#include <vector>

namespace AdventOfCode {
    enum Command {
        WRITE,
        AND,
        OR,
        LSHIFT,
        RSHIFT,
        NOT
    };

    struct Address {
        std::string name = {"NULL"};
        uint16_t value = 0;
    };

    struct Action {
        Command command;
        Address from_address_x;
        Address from_address_y;
        Address to_address;
    };

    class DaySeven {
    public:
        static std::vector<Action> parse(const std::vector<std::string> &data);
        static int solve(const std::vector<Action>& assembly);
    };
}


#endif //ADVENTOFCODE_DAYSEVEN_H
