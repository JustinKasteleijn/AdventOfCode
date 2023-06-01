//
// Created by justi on 6/1/2023.
//

#ifndef ADVENTOFCODE_DAYTWENTYONE_H
#define ADVENTOFCODE_DAYTWENTYONE_H

#include <vector>
#include <string>
#include <functional>

namespace AdventOfCode {

    class DayTwentyOne {
    public:
        static int solve(const std::vector<std::string> &data);

        static int solve2(const std::vector<std::string> &data);

    private:
        struct Unit {
            std::string name;
            int32_t hp;
            int32_t damage;
            int32_t armor;
        };

        struct Item {
            std::string name;
            int32_t cost;
            int32_t damage;
            int32_t armor;
        };

        static std::vector<Item> weapons;

        static std::vector<Item> armor;

        static std::vector<Item> rings;

        static void equip(Unit &unit, const Item &item);

        static void unequip(Unit &unit, const Item &item);

        static bool playerWins(const Unit &player, const Unit &boss);

        static bool playerWinsSimulation(Unit &player, Unit &boss);

        static Unit parse(const std::vector<std::string> &data);

    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYTWENTYONE_H
