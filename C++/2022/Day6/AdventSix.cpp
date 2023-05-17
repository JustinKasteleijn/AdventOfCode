//
// Created by justi on 12/19/2022.
//

#include <set>
#include "AdventSix.h"

int AdventSix::find_subroutine(std::string &routine, const int& set_size) const {
    std::set<char> unique_chars;
    int index = -1;
    for(int i = 0; i < routine.size(); ++i) {
        if(unique_chars.find(routine[i]) == unique_chars.end()) {
            unique_chars.emplace(routine[i]);
        } else {
            unique_chars.clear();
            index++;
            i = index;
        }

        if(unique_chars.size() == set_size) {
            return i += 1;
        }
    }
    return -1;
}
