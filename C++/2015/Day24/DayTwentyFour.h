//
// Created by justi on 6/1/2023.
//

#ifndef ADVENTOFCODE_DAYTWENTYFOUR_H
#define ADVENTOFCODE_DAYTWENTYFOUR_H

#include <vector>
#include <string>
#include <numeric>
#include <algorithm>


namespace AdventOfCode {

    class DayTwentyFour {
    public:
        static uint64_t solve(const std::vector<std::string> &data, int groups);

    private:
        template <typename T>
        static void genCombinationSumUtil(size_t l, T sum, T K, std::vector<T>& local, const std::vector<T>& A, std::vector<std::vector<T>>& out) {
            if (sum == K) {
                out.push_back(local);
                return;
            }

            for (size_t i = l; i < A.size(); i++) {
                if (sum + A[i] > K)
                    continue;

                local.push_back(A[i]);
                genCombinationSumUtil(i + 1, sum + A[i], K, local, A, out);
                local.pop_back();
            }
        }

        template <typename T>
        static void genCombinationSum(const std::vector<T>& A, T sum, std::vector<std::vector<T>>& out) {
            std::vector<T> sortedA = A;  // Create a copy of A to avoid modifying the original vector
            std::sort(sortedA.begin(), sortedA.end());

            std::vector<T> local;
            genCombinationSumUtil(0, 0, sum, local, sortedA, out);
        }

    };
} // AdventOfCode

#endif //ADVENTOFCODE_DAYTWENTYFOUR_H
