//
// Created by justi on 5/31/2023.
//

#ifndef ADVENTOFCODE_DAYNINETEEN_H
#define ADVENTOFCODE_DAYNINETEEN_H

#include <map>
#include <vector>

namespace AdventOfCode {


    class DayNineteen {
        using Reps = std::multimap<std::string, std::string>;

        static Reps read(std::string &molecule, const std::vector<std::string> &data);

    public:
        static int solve(std::string &molecule, const std::vector<std::string> &data);

        static int create_molecule(const Reps &replacements, std::string &source);

        static Reps reverse_map(const Reps &source);

        static int solve2(const std::vector<std::string> &data, std::string &molecule);
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYNINETEEN_H
