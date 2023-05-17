//
// Created by justi on 12/6/2022.
//

#include <iostream>
#include "AdventOne.h"

AdventOne::AdventOne() = default;

int AdventOne::totalSingleElf() {
    int total = 0;
    while(!calories.empty() && calories.at(0) != '\n') {
        total += parseSingleValue();
    }
    calories.erase(0, 1);
    return total;
}

int AdventOne::parseSingleValue() {
    auto positionOfCalories = this->calories.find('\n');
    auto meal = this->calories.substr(0, positionOfCalories);
    calories.erase(0, positionOfCalories + 1);
    return std::stoi(meal);
}

int AdventOne::getHighestElf() {
    int highest = 0;
    while(!calories.empty()) {
        int temp = totalSingleElf();
        if(temp > highest) {
            highest = temp;
        }
    }
    return highest;
}

int AdventOne::getHighestThreeElfs() {
    int highest = 0;
    int middle = 0;
    int lowest = 0;
    while(!calories.empty()) {
        int temp = totalSingleElf();
        if(temp > highest) {
            lowest = middle;
            middle = highest;
            highest = temp;
            continue;
        }
        if(temp > middle) {
            lowest = middle;
            middle = temp;
            continue;
        }
        if(temp > lowest) {
            lowest = temp;
            continue;
        }
    };
    std::cout << lowest << ' ' << middle << ' ' << highest << '\n';
    return (highest + middle + lowest);
}
