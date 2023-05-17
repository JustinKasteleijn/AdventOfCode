//
// Created by justi on 5/15/2023.
//

#include "File.h"
#include <fstream>
#include <utility>
#include <iostream>

namespace AdventOfCode {
    File::File(std::string filename) : filename(std::move(filename)) {}

    std::vector<std::string> File::to_vector(int rows) {
        std::vector<std::string> file_data;
        file_data.reserve(rows);
        std::ifstream file(this->filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                file_data.push_back(line);
            }
        }
        file.close();
        return std::move(file_data);
    }

    std::string File::to_string() {
        std::string file_data;
        std::ifstream file(this->filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                file_data.append(line);
            }
        }
        file.close();
        return std::move(file_data);
    }
} // AdventOfCode
