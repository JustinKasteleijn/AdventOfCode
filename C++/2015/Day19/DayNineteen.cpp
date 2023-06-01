//
// Created by justi on 5/31/2023.
//

#include <regex>
#include "DayNineteen.h"

namespace AdventOfCode {
    DayNineteen::Reps DayNineteen::read(std::string &molecule, const std::vector<std::string> &data) {
        std::regex rex("(\\w+) => (\\w+)");
        std::smatch match;
        Reps replacements;

        for (const std::string &line: data) {
            if (std::regex_match(line, match, rex)) {
                if (match.size() < 3)
                    return replacements;
                replacements.insert(std::make_pair(match[1], match[2]));
            } else {
                molecule = line;
            }
        }
        return replacements;
    }

    int DayNineteen::solve(std::string &molecule, const std::vector<std::string> &data) {
        Reps replacements = read(molecule, data);
        std::map<std::string, int> newMolecules;
        for (const auto &rep: replacements) {
            size_t pos = molecule.find(rep.first, 0);
            while (pos != std::string::npos) {
                std::string mol = molecule;
                mol.replace(pos, rep.first.length(), rep.second);
                newMolecules[mol] = 1;
                pos = molecule.find(rep.first, pos + 1);
            }
        }
        return static_cast<int>(newMolecules.size());
    }

    int DayNineteen::create_molecule(const Reps &replacements, std::string &source) {
        int steps = 0;

        for (;;) {
            for (const auto &rep: replacements) {
                auto pos = source.find(rep.first, 0);
                if (pos != std::string::npos) {
                    source.replace(pos, rep.first.length(), rep.second);
                    steps++;
                }
                if (source == "e")
                    return steps;
            }
        }
    }

    DayNineteen::Reps DayNineteen::reverse_map(const Reps &source) {
        DayNineteen::Reps rest;
        for (auto &element: source) {
            rest.insert(std::make_pair(element.second, element.first));
        }
        return rest;
    }

    int DayNineteen::solve2(const std::vector<std::string> &data, std::string &molecule) {
        Reps replacements = read(molecule, data);
        return create_molecule(reverse_map(replacements), molecule);
    }
} // AdventOfCode


