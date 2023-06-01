//
// Created by justi on 6/1/2023.
//

#ifndef ADVENTOFCODE_DAYTWENTYTWO_H
#define ADVENTOFCODE_DAYTWENTYTWO_H

#include <map>
#include <vector>

namespace AdventOfCode {

    class DayTwentyTwo {
    public:
        static int parse(const std::vector<std::string>& data);

    private:
        struct Spell {
            int manaCost;
            int manaProfit;
            int time;
            int damage;
            int hit;
            int armor;

            Spell() {
                this->manaCost = 0;
                this->manaProfit = 0;
                this->time = 0;
                this->damage = 0;
                this->hit = 0;
                this->armor = 0;
            }

            Spell(int manaCost, int manaProfit, int time, int damage, int hit, int armor) {
                this->manaCost = manaCost;
                this->manaProfit = manaProfit;
                this->time = time;
                this->damage = damage;
                this->hit = hit;
                this->armor = armor;
            }
        };


        struct Player {
            int mana;
            int hit;
            int armor;
            int damage;

            std::map<std::string, int> spells;

            Player() {
                this->mana = 0;
                this->hit = 0;
                this->armor = 0;
                this->damage = 0;
            }

            Player(int hit, int mana) {
                this->hit = hit;
                this->mana = mana;
                this->armor = 0;
                this->damage = 0;
            }
        };

    private:
        static void _commitSpell(Player &user, Player &boss, const Spell &spell);

        static void
        _turn(const std::map<std::string, Spell> &spells, Player &user, Player &boss, int userDecrease, bool userTurn,
              int manaUsed, int &min);

        static Player init_boss(const std::vector<std::string> &data);

        static std::map<std::string, Spell> init_spells();
    };
} // AdventOfCode

#endif //ADVENTOFCODE_DAYTWENTYTWO_H
