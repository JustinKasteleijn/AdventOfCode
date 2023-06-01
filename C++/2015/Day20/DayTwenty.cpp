//
// Created by justi on 5/31/2023.
//

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "DayTwenty.h"

namespace AdventOfCode {
    int DayTwenty::solve(int target) {
        int house = 0;

        while (true) {
            int presents = 0;

            int sqrt = static_cast<int>(std::sqrt(house));
            for (int i = 1; i <= sqrt; ++i) {
                if (house % i == 0) {
                    presents += i * 10;
                    presents += (house / i) * 10;
                }
            }
            if (presents >= target) {
                return house;
            }
            house++;
        }
    }

    int DayTwenty::number_of_presents2(int housenumber) {
        int presents = 0;
        for (int i = 1; i <= housenumber; ++i) {
            if (housenumber % i == 0) {
                if (housenumber/i<50) {
                    presents += i*11;
                }
            }
        }
        return presents;
    }

    int DayTwenty::solve2(int target) {
        int current_house = 1;
        while (true) {
            int nop = number_of_presents2(current_house);
            if (nop>=target) return current_house;
            ++current_house;
        }
    }


} // AdventOfCode
