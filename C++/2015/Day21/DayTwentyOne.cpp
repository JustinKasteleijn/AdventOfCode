//
// Created by justi on 6/1/2023.
//

#include <cmath>
#include "DayTwentyOne.h"
#include "../../StringUtils.h"

namespace AdventOfCode {


    int DayTwentyOne::solve(const std::vector<std::string> &data) {
        Unit player{"Player", 100, 0, 0};
        Unit boss = parse(data);

        int32_t result = std::numeric_limits<int32_t>::max();

        for (const auto &w: weapons) {

            Unit &p = player;
            const Unit &b = boss;

            int32_t cost = w.cost;
            equip(p, w);

            // Just weapon
            if (playerWins(p, b)) {
                result = std::min(result, cost);
            }

            for (const auto &a: armor) {

                cost += a.cost;
                equip(p, a);

                // Weapon + Armor
                if (playerWins(p, b)) {
                    result = std::min(result, cost);
                }

                for (size_t i = 0; i < rings.size(); i++) {
                    cost += rings[i].cost;
                    equip(p, rings[i]);

                    // Weapon + Armor + 1 ring
                    if (playerWins(p, b)) {
                        result = std::min(result, cost);
                    }

                    for (size_t j = i + 1; j < rings.size(); j++) {
                        cost += rings[j].cost;
                        equip(p, rings[j]);

                        // Weapon + Armor + 2 rings
                        if (playerWins(p, b)) {
                            result = std::min(result, cost);
                        }

                        cost -= rings[j].cost;
                        unequip(p, rings[j]);
                    }

                    cost -= rings[i].cost;
                    unequip(p, rings[i]);
                }

                cost -= a.cost;
                unequip(p, a);
            }

            for (size_t i = 0; i < rings.size(); i++) {
                cost += rings[i].cost;
                equip(p, rings[i]);

                // Weapon + 1 ring
                if (playerWins(p, b)) {
                    result = std::min(result, cost);
                }

                for (size_t j = i + 1; j < rings.size(); j++) {
                    cost += rings[j].cost;
                    equip(p, rings[j]);

                    // Weapon + 2 rings
                    if (playerWins(p, b)) {
                        result = std::min(result, cost);
                    }

                    cost -= rings[j].cost;
                    unequip(p, rings[j]);
                }

                cost -= rings[i].cost;
                unequip(p, rings[i]);
            }

            // Remove weapon here
            cost -= w.cost;
            unequip(p, w);
        }

        return result;
    }

    int DayTwentyOne::solve2(const std::vector<std::string> &data) {
        Unit player{"Player", 100, 0, 0};
        Unit boss = parse(data);

        int32_t result = std::numeric_limits<int32_t>::min();

        for (const auto &w: weapons) {

            Unit &p = player;
            const Unit &b = boss;

            int32_t cost = w.cost;
            equip(p, w);

            // Just weapon
            if (!playerWins(p, b)) {
                result = std::max(result, cost);
            }

            for (const auto &a: armor) {

                cost += a.cost;
                equip(p, a);

                // Weapon + Armor
                if (!playerWins(p, b)) {
                    result = std::max(result, cost);
                }

                for (size_t i = 0; i < rings.size(); i++) {
                    cost += rings[i].cost;
                    equip(p, rings[i]);

                    // Weapon + Armor + 1 ring
                    if (!playerWins(p, b)) {
                        result = std::max(result, cost);
                    }

                    for (size_t j = i + 1; j < rings.size(); j++) {
                        cost += rings[j].cost;
                        equip(p, rings[j]);

                        // Weapon + Armor + 2 rings
                        if (!playerWins(p, b)) {
                            result = std::max(result, cost);
                        }

                        cost -= rings[j].cost;
                        unequip(p, rings[j]);
                    }

                    cost -= rings[i].cost;
                    unequip(p, rings[i]);
                }

                cost -= a.cost;
                unequip(p, a);
            }

            for (size_t i = 0; i < rings.size(); i++) {
                cost += rings[i].cost;
                equip(p, rings[i]);

                // Weapon + 1 ring
                if (!playerWins(p, b)) {
                    result = std::max(result, cost);
                }

                for (size_t j = i + 1; j < rings.size(); j++) {
                    cost += rings[j].cost;
                    equip(p, rings[j]);

                    // Weapon + 2 rings
                    if (!playerWins(p, b)) {
                        result = std::max(result, cost);
                    }

                    cost -= rings[j].cost;
                    unequip(p, rings[j]);
                }

                cost -= rings[i].cost;
                unequip(p, rings[i]);
            }

            // Remove weapon here
            cost -= w.cost;
            unequip(p, w);
        }

        return result;
    }

    DayTwentyOne::Unit DayTwentyOne::parse(const std::vector<std::string> &data) {
        std::vector<int> stats;
        stats.reserve(3);
        for (const std::string &split: data)
            stats.emplace_back(std::stoi(StringUtils::split_string(split, ':').at(1)));

        return Unit{"Boss", stats.at(0), stats.at(1), stats.at(2)};
    }

    std::vector<DayTwentyOne::Item> DayTwentyOne::weapons = {
            Item{"Dagger", 8, 4, 0},
            Item{"Shortsword", 10, 5, 0},
            Item{"Warhammer", 25, 6, 0},
            Item{"Longsword", 40, 7, 0},
            Item{"Greataxe", 74, 8, 0},
    };

    std::vector<DayTwentyOne::Item> DayTwentyOne::armor = {
            Item{"Leather", 13, 0, 1},
            Item{"Chainmail", 31, 0, 2},
            Item{"Splintmail", 53, 0, 3},
            Item{"Bandedmail", 75, 0, 4},
            Item{"Platemail", 102, 0, 5},
    };

    std::vector<DayTwentyOne::Item> DayTwentyOne::rings = {
            Item{"Damage +1", 25, 1, 0},
            Item{"Damage +2", 50, 2, 0},
            Item{"Damage +3", 100, 3, 0},
            Item{"Defense +1", 20, 0, 1},
            Item{"Defense +2", 40, 0, 2},
            Item{"Defense +3", 80, 0, 3},
    };

    void DayTwentyOne::equip(DayTwentyOne::Unit &unit, const DayTwentyOne::Item &item) {
        unit.damage += item.damage;
        unit.armor += item.armor;
    }

    void DayTwentyOne::unequip(Unit &unit, const Item &item) {
        unit.damage -= item.damage;
        unit.armor -= item.armor;
    }

    bool DayTwentyOne::playerWins(const Unit &player, const Unit &boss) {

        int32_t pturns = std::ceil(1.0 * boss.hp / std::max(1, player.damage - boss.armor));
        int32_t bturns = std::ceil(1.0 * player.hp / std::max(1, boss.damage - player.armor));

        return (pturns <= bturns);
    }

    bool DayTwentyOne::playerWinsSimulation(Unit &player, Unit &boss) {

        Unit units[] = {player, boss};

        uint8_t active = 0;

        while (true) {
            auto attacker = &units[active];
            auto victim = &units[1 - active];

            int32_t dealt = std::max(1, attacker->damage - victim->armor);
            victim->hp = std::max(0, victim->hp - dealt);

            if (victim->hp <= 0) {
                break;
            }
            active = 1 - active;
        }

        return units[1].hp <= 0;
    }
} // AdventOfCode
