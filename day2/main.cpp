#include <iostream>
#include "input.hpp"


bool check_entry(const std::vector<int>& entry)
{
    if (entry.empty())
        return false;

    int direction = 0;      // 1 for increasing, -1 for decreasing, 0 for base state
    bool safe = true;

    for (int i = 0; i < entry.size() - 1; i++)
    {
        int dif = entry[i] - entry[i + 1];
        if (dif == 0)
        {
            safe = false;
            break;
        }
        if (direction == 0)
            direction = dif / -abs(dif);

        if (abs(dif) > 3 || dif / direction > 0)
        {
            safe = false;
            break;
        }
    }

    return safe;
}
int main()
{
    std::vector<int> entry = fetch_entry();
    int safe_entries = 0;

    while (!entry.empty())
    {
        if (check_entry(entry))
        {
            safe_entries++;
        }
        else
        {
            for (int i = 0; i < entry.size(); i++)
            {
                std::vector<int> corrected = entry;
                corrected.erase(corrected.begin() + i);
                if (check_entry(corrected))
                {
                    safe_entries++;
                    break;
                }
            }
        }

        entry = fetch_entry();
    }

    std::cout << safe_entries;
    return 0;
}