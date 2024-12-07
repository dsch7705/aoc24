#include <iostream>
#include "input.hpp"


int main()
{
    auto pairs = fetch_pairs();
    int total = 0;

    for (const auto& p : pairs)
    {
        total += p.first * p.second;
    }
    std::cout << total;

    return 0;
}