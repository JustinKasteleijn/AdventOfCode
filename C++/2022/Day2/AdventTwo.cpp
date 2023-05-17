//
// Created by justi on 12/6/2022.
//

#include "AdventTwo.h"

AdventTwo::AdventTwo() {
    playerOneMoves.push_back('A');
    playerOneMoves.push_back('B');
    playerOneMoves.push_back('C');

    playerTwoMoves.push_back('X');
    playerTwoMoves.push_back('Y');
    playerTwoMoves.push_back('Z');
}

std::pair<char, char> AdventTwo::parse() {
    auto pos = this->strategy.find('\n');
    auto moves = this->strategy.substr(0, pos);
    strategy.erase(0, pos + 1);

    auto playerOne = moves.at(0);
    auto playerTwo = moves.at(2);
    return {playerOne, playerTwo};
}

int AdventTwo::playRound(std::pair<char, char> moves) {
    if(moves.first == 'A') {
        if(moves.second == 'X') {
            return 3 + 1;
        }
        if(moves.second == 'Y') {
            return 6 + 2;
        }
        if(moves.second == 'Z') {
            return 0 + 3;
        }
    }
    if(moves.first == 'B') {
        if(moves.second == 'X') {
            return 0 + 1;
        }
        if(moves.second == 'Y') {
            return 3 + 2;
        }
        if(moves.second == 'Z') {
            return 6 + 3;
        }
    }
    if(moves.first == 'C') {
        if(moves.second == 'X') {
            return 6 + 1;
        }
        if(moves.second == 'Y') {
            return 0 + 2;
        }
        if(moves.second == 'Z') {
            return 3 + 3;
        }
    }
    return 0;
}

int AdventTwo::play() {
    int score = 0;
    while(!this->strategy.empty()) {
        score += playRound(parse());
    }
    return score;
}

int AdventTwo::playRoundTwo(std::pair<char, char> moves) {
    if(moves.first == 'A') {
        if (moves.second == 'X') {
            return 0 + 3;
        }
        if (moves.second == 'Y') {
            return 3 + 1;
        }
        if (moves.second == 'Z') {
            return 6 + 2;
        }
    }
    if(moves.first == 'B') {
        if (moves.second == 'X') {
            return 0 + 1;
        }
        if (moves.second == 'Y') {
            return 3 + 2;
        }
        if (moves.second == 'Z') {
            return 6 + 3;
        }
    }
    if(moves.first == 'C') {
        if (moves.second == 'X') {
            return 0 + 2;
        }
        if (moves.second == 'Y') {
            return 3 + 3;
        }
        if (moves.second == 'Z') {
            return 6 + 1;
        }
    }
    return 0;
}

int AdventTwo::playTwo() {
    int score = 0;
    while(!this->strategy.empty()) {
        score += playRoundTwo(parse());
    }
    return score;
}
