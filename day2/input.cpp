#include "input.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


std::vector<int> fetch_entry()
{
    static std::ifstream filestream("../input.txt");
    if (filestream.fail())
    {
        std::cout << "'input.txt' was not found.\n";
        return {};
    }

    std::string line;
    std::getline(filestream, line);
    if (filestream.eof())
    {
        filestream.close();
        return {};
    }

    std::vector<int> entry;
    std::stringstream line_ss(line);

    std::string s;
    while (std::getline(line_ss, s, ' '))
    {
        entry.push_back(std::stoi(s));
    }

    return entry;
}