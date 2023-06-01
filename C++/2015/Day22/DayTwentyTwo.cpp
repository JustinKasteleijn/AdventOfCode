//
// Created by justi on 6/1/2023.
//

#include "DayTwentyTwo.h"
#include "../../StringUtils.h"

namespace AdventOfCode {
    int DayTwentyTwo::parse(const std::vector<std::string> &data) {
        Player user{50, 500};
        Player boss = init_boss(data);
        std::map<std::string, Spell> spells = init_spells();

        int min_mana = std::numeric_limits<int>::max();
        _turn(spells, user, boss, 1, true, 0, min_mana);
        return min_mana;
    }

    void DayTwentyTwo::_commitSpell(DayTwentyTwo::Player &user, DayTwentyTwo::Player &boss,
                                    const DayTwentyTwo::Spell &spell) {
        user.mana += spell.manaProfit;
        user.hit += spell.hit;

        boss.hit -= spell.damage;
    };

    void DayTwentyTwo::_turn(const std::map<std::string, DayTwentyTwo::Spell> &spells, DayTwentyTwo::Player &user,
                             DayTwentyTwo::Player &boss, int userDecrease, bool userTurn, int manaUsed, int &min) {
        bool anyOneLost = false;

        // Ignore fights overflowing current min mana
        if (manaUsed > min) {
            return;
        }

        user.hit -= userDecrease;

        // Apply effects
        if (! anyOneLost) {
            std::map<std::string, int>::iterator s = user.spells.begin();
            while (s != user.spells.end()) {
                const Spell &spell = spells.at(s->first);

                _commitSpell(user, boss, spell);

                // Timer
                s->second++;

                if (s->second == spell.time) {
                    s = user.spells.erase(s);

                    user.armor -= spell.armor;

                } else {
                    s++;
                }
            }

            if (boss.hit <= 0 || user.hit <= 0) {
                anyOneLost = true;
            }
        }

        if (! anyOneLost) {
            if (userTurn) {
                std::vector<std::string> possibleSpells;

                // Possible spells
                for (auto &s : spells) {
                    if (s.second.manaCost <= user.mana) {
                        if (user.spells.find(s.first) == user.spells.end()) {
                            possibleSpells.push_back(s.first);
                        }
                    }
                }

                if (possibleSpells.size() == 0) {
                    // User has not enough mana
//				anyOneLost = true;

                } else {
                    int    outMana = manaUsed;
                    Player outBoss = boss;

                    for (auto &spellName : possibleSpells) {
                        const Spell &toCast = spells.at(spellName);

                        Player nextUser = user;
                        Player nextBoss = boss;
                        int    nextMana = manaUsed;

                        nextUser.mana -= toCast.manaCost;
                        nextMana      += toCast.manaCost;

                        if (toCast.time == 0) {
                            _commitSpell(nextUser, nextBoss, toCast);

                        } else {
                            nextUser.spells[spellName] = 0;

                            nextUser.armor += toCast.armor;
                        }

                        if (nextBoss.hit > 0) {
                            _turn(spells, nextUser, nextBoss, userDecrease, false, nextMana, min);

                        } else {
                            outMana    = nextMana;
                            outBoss    = nextBoss;
                            anyOneLost = true;
                        }
                    }

                    if (anyOneLost) {
                        manaUsed = outMana;
                        boss     = outBoss;
                    }
                }

            } else {
                int damage = std::max(1, boss.damage - user.armor);

                user.hit -= damage;
                if (user.hit <= 0) {
                    anyOneLost = true;

                } else {
                    _turn(spells, user, boss, userDecrease, true, manaUsed, min);
                }
            }
        }

        if (anyOneLost) {
            if (boss.hit <= 0 && user.hit > 0) {
                if (manaUsed < min) {
                    min = manaUsed;
                }
            }
        }
    }

    DayTwentyTwo::Player DayTwentyTwo::init_boss(const std::vector<std::string> &data) {
        Player boss;
        boss.hit = std::stoi(StringUtils::split_string(data.front(), ":").second);
        boss.damage = std::stoi(StringUtils::split_string(data.back(), ":").second);
        return boss;
    }

    std::map<std::string, DayTwentyTwo::Spell> DayTwentyTwo::init_spells() {
        std::map<std::string, Spell> spells;
        spells["Magic Missile"] = Spell(53, 0, 0, 4, 0, 0);
        spells["Drain"] = Spell(73, 0, 0, 2, 2, 0);
        spells["Shield"] = Spell(113, 0, 6, 0, 0, 7);
        spells["Poison"] = Spell(173, 0, 6, 3, 0, 0);
        spells["Recharge"] = Spell(229, 101, 5, 0, 0, 0);
        return spells;
    }
} // AdventOfCode
