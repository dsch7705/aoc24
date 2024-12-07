#include "input.hpp"
#include <iostream>
#include <sstream>


std::vector<std::pair<int, int>> fetch_pairs()
{
    static std::ifstream filestream("../input.txt");
    if (filestream.fail())
    {
        std::cout << "'input.txt' not found.\n";
        return {};
    }

    std::stringstream buf;
    buf << filestream.rdbuf();
    std::string data = buf.str();
    
    std::vector<std::pair<int, int>> pairs;
    bool mul_enabled = true;
    for (int i = 0; i < data.size(); i++)
    {
        if (data.substr(i, 4) == "mul(" && mul_enabled)
        {
            std::string first_n_buf, second_n_buf;
            bool valid_mul = false;
            int current_n = 1;

            for (int j = i + 4; j < i + 12; j++)
            {
                if (data[j] >= '0' && data[j] <= '9')
                {
                    if (current_n == 1 && first_n_buf.length() < 4)
                        first_n_buf.push_back(data[j]);
                    else if (current_n == 2 && second_n_buf.length() < 4)
                        second_n_buf.push_back(data[j]);
                }
                else if (data[j] == ',')
                    current_n = 2;
                else if (data[j] == ')')
                {
                    if (!first_n_buf.empty() && !second_n_buf.empty())
                        valid_mul = true;
                    break;
                }
                else
                    break;
            }

            if (valid_mul)
            {
                std::pair<int, int> entry(std::stoi(first_n_buf), std::stoi(second_n_buf));
                pairs.push_back(entry);
            }
        }
        else if (data.substr(i, 4) == "do()")
            mul_enabled = true;
        else if (data.substr(i, 7) == "don't()")
            mul_enabled = false;
    }

    return pairs;
}