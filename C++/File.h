//
// Created by justi on 5/15/2023.
//

#ifndef C___FILE_H
#define C___FILE_H

#include <string>
#include "vector"

namespace AdventOfCode {

    class File {
    public:
        explicit File(std::string filename);

    public:
        std::vector<std::string> to_vector(int rows);

        std::string to_string();

    private:
        std::string filename;
    };

} // AdventOfCode

#endif //C___FILE_H
