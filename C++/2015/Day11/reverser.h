//
// Created by justi on 5/22/2023.
//

#ifndef ADVENTOFCODE_REVERSER_H
#define ADVENTOFCODE_REVERSER_H

/*
 * Ranges is not available so simple version of std::ranges::reverse_view is provided
 */
template<typename T>
class reverser_impl {
    typename T::reverse_iterator b, e;

public:
    reverser_impl(T &data) : b{data.rbegin()}, e{data.rend()} {}

    typename T::reverse_iterator begin() {
        return b;
    }

    typename T::reverse_iterator begin() const {
        return b;
    }

    typename T::reverse_iterator end() {
        return e;
    }

    typename T::reverse_iterator end() const {
        return e;
    }
};

template<typename T>
reverser_impl<T> reverser(T &data) {
    return {data};
}

#endif //ADVENTOFCODE_REVERSER_H
