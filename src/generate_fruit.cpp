#include <iostream>
#include <random>
#include <ranges>
#include <vector>


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

enum class cell
{
    empty = 0,
    snake,
    fruit
};

using game_board = std::vector<std::vector<cell>>;

std::ostream& operator<<(std::ostream& str, cell c)
{
    switch (c)
    {
    case cell::empty:
        str << " - ";
        break;
    case cell::snake:
        str << " # ";
        break;
    case cell::fruit:
        str << " o ";
        break;
    }
    
    return str;
}

std::ostream& operator<<(std::ostream& str, const game_board& _board)
{
    for (const auto& row : _board)
    {
        for (const auto cell : row)
            std::cout << cell;
        std::cout << std::endl;
    }
    return str;
}

auto board = game_board {
    { cell::empty, cell::empty, cell::empty, cell::empty, cell::empty },
    { cell::snake, cell::snake, cell::snake, cell::empty, cell::fruit },
    { cell::snake, cell::empty, cell::empty, cell::empty, cell::empty },
    { cell::snake, cell::snake, cell::empty, cell::empty, cell::empty },
    { cell::empty, cell::snake, cell::empty, cell::empty, cell::empty }
};
 
int main()
{
    std::cout << "before: \n" << board << "\n" << std::endl;

    auto empties = [](const cell c){
        return c == cell::empty;
    };
    
    auto rnd_it = select_randomly(std::views::join(board) | std::views::filter(empties));
    *rnd_it = cell::fruit;

    std::cout << "after: \n" << board << "\n" << std::endl;

    return 0;
}