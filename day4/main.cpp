#include "input.hpp"
#include <algorithm>
#include <iostream>


int main()
{
    // part one
    std::vector<std::string> input = fetch_input(1);
    int xmas_occurances = 0;

    for (std::string str : input)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str.substr(i, 4) == "XMAS")
            {
                xmas_occurances++;
            }
        }

        std::reverse(str.begin(), str.end());
        for (int i = 0; i < str.length(); i++)
        {
            if (str.substr(i, 4) == "XMAS")
            {
                xmas_occurances++;
            }
        }
    }

    // part 
    int x_mas_occurances = 0;
    std::vector<std::string> input_2 = fetch_input(2);
    for (int y = 0; y < input_2.size() - 2; y++)
    {
        for (int x = 0; x < input_2.size() - 2; x++)
        {
            if (input_2[y + 1][x + 1] != 'A')
                continue;

            std::string neg_diag = {input_2[y][x], input_2[y + 1][x + 1], input_2[y + 2][x + 2]};
            std::string pos_diag = {input_2[y + 2][x], input_2[y + 1][x + 1], input_2[y][x + 2]};
            if ((neg_diag == "MAS" || neg_diag == "SAM") && (pos_diag == "MAS" || pos_diag == "SAM"))
                x_mas_occurances++;
        }
    }

    std::cout << "Part one: " << xmas_occurances << '\n' << "Part two: " << x_mas_occurances << std::endl;
    return 0;
}