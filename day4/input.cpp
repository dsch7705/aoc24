#include "input.hpp"
#include <fstream>
#include <iostream>


std::vector<std::string> fetch_input(int part)
{
    std::ifstream filestream("../input.txt");
    if (filestream.fail())
    {
        std::cout << "'input.txt' not found.\n";
        return {};
    }

    std::vector<std::string> rows;
    std::vector<std::string> cols;
    std::vector<std::string> input;
    std::string line;
    // rows
    while (std::getline(filestream, line))
    {
        rows.push_back(line);
        input.push_back(line);
    }
    // cols
    for (int x = 0; x < rows.size(); x++)
    {
        std::string col;
        for (int y = 0; y < rows.size(); y++)
        {
            col.push_back(rows[y][x]);
        }

        cols.push_back(col);
        input.push_back(col);
    }
    // diags
    int n = 0;
    // main
    std::string neg_main, pos_main;
    for (int i = 0; i < rows.size(); i++)
    {
        neg_main.push_back(rows[i][i]);
        pos_main.push_back(rows[rows.size() - 1 - i][i]);
    }
    input.push_back(neg_main);
    input.push_back(pos_main);

    // sub/super
    for (int y = rows.size() - 1; y > 0; y--)
    {
        std::string neg_sub, neg_super, pos_sub, pos_super;
        for (int i = 0; i < cols.size(); i++)
        {
            if (y + i > rows.size() - 1)
                break;

            neg_sub.push_back(rows[y + i][i]);
            neg_super.push_back(rows[i][y + i]);
            pos_sub.push_back(rows[y + i][cols.size() - i - 1]);
            pos_super.push_back(rows[i][cols.size() - (y + i) - 1]);
        }
        input.push_back(neg_sub);
        input.push_back(neg_super);
        input.push_back(pos_sub);
        input.push_back(pos_super);
    }

    return part == 1 ? input : rows;
}