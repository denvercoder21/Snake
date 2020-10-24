#pragma once

#include <iterator>
#include <random>

struct element
{
    int x,
        y;
};

inline bool operator==(const element& a, const element& b)
{
    return a.x == b.x && a.y == b.y;
}

// https://stackoverflow.com/questions/6942273/how-to-get-a-random-element-from-a-c-container
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Range>
auto select_randomly(Range rng) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(rng.begin(), rng.end(), gen);
}
