//
// Created by justi on 6/1/2023.
//

#ifndef ADVENTOFCODE_DAYTWENTYTHREE_H
#define ADVENTOFCODE_DAYTWENTYTHREE_H

#include <vector>
#include <string>

namespace AdventOfCode {

    class DayTwentyThree {
    public:
        static int parse(const std::vector<std::string> &data);

    private:
        struct Computer {
            unsigned int reg[2]{};
            int pc;

            void reset() {
                this->pc = 0;
                this->reg[0] = 0;
                this->reg[1] = 0;
            }

            Computer() {
                this->reg[0] = 0;
                this->reg[1] = 0;

                this->pc = 0;
            }

            int run(const std::vector<std::string> &code) {
                while (this->pc < code.size()) {
                    const std::string &opcode = code[this->pc];

                    if (opcode.compare(0, 3, "hlf") == 0) {
                        this->reg[opcode[4] - 'a'] >>= 1;
                        this->pc++;

                    } else if (opcode.compare(0, 3, "tpl") == 0) {
                        this->reg[opcode[4] - 'a'] *= 3;
                        this->pc++;

                    } else if (opcode.compare(0, 3, "inc") == 0) {
                        this->reg[opcode[4] - 'a']++;
                        this->pc++;

                    } else if (opcode.compare(0, 3, "jmp") == 0) {
                        this->pc += std::stoi(opcode.substr(4));

                    } else if (opcode.compare(0, 3, "jie") == 0) {
                        if ((this->reg[opcode[4] - 'a'] & 0x01) == 0) {
                            this->pc += std::stoi(opcode.substr(7));

                        } else {
                            this->pc++;
                        }

                    } else if (opcode.compare(0, 3, "jio") == 0) {
                        if (this->reg[opcode[4] - 'a'] == 1) {
                            this->pc += std::stoi(opcode.substr(7));

                        } else {
                            this->pc++;
                        }
                    } else {
                        abort();
                    }
                }
                return static_cast<int>(this->reg[1]);
            }
        };
    };

} // AdventOfCode

#endif //ADVENTOFCODE_DAYTWENTYTHREE_H
