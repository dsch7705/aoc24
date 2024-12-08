#include "input.hpp"
#include <iostream>
#include <algorithm>


bool illegal(const std::vector<int>& prohibited, const std::vector<int>& seen)
{
    for (const auto&p : prohibited)
    {
        if (std::find(seen.begin(), seen.end(), p) != seen.end())
            return true;
    }

    return false;
}
void reorder(const std::unordered_map<int, std::vector<int>>& ruleset, std::vector<int>& update)
{
    for (int i = 0; i < update.size(); i++)
    {
        for (int j = i + 1; j < update.size(); j++)
        {
            const std::vector<int>& rules = ruleset.at(update[j]);
            if (std::find(rules.begin(), rules.end(), update[i]) != rules.end())
            {
                int tmp = update[i];
                update[i] = update[j];
                update[j] = tmp;

                i = 0;
            }
        }
    }
}

int main()
{
    auto rules = fetch_rules();
    auto updates = fetch_updates();

    int p1_middle_sum = 0;
    int p2_middle_sum = 0;
    std::vector<std::vector<int>> needs_reordered;
    // part one
    for (auto& update : updates)
    {
        std::vector<int> seen;
        bool legal_update = true;
        for (const auto& page : update)
        {
            if (illegal(rules[page], seen))
            {
                needs_reordered.push_back(update);
                legal_update = false;
                break;
            }
            seen.push_back(page);
        }
        if (legal_update)
            p1_middle_sum += update[(update.size() - 1) / 2];
    }
    // part two
    for (auto& update : needs_reordered)
    {
        reorder(rules, update);
        p2_middle_sum += update[(update.size() - 1) / 2];
    }
    std::cout << p1_middle_sum << '\n' << p2_middle_sum << std::endl;
    return 0;
}