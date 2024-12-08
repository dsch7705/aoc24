#include "input.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


std::unordered_map<int, std::vector<int>> fetch_rules()
{
    std::ifstream filestream("../input.txt");
    if (filestream.fail())
    {
        std::cout << "'input.txt' not found.\n";
        return {};
    }
    int rules_total = 0;
    std::unordered_map<int, std::vector<int>> rules;
    std::string line;
    while (std::getline(filestream, line))
    {
        if (line.find('|') == std::string::npos)
            break;

        std::pair<int, int> rule(std::stoi(line.substr(0, 2)), std::stoi(line.substr(3, 2)));
        rules[rule.first].push_back(rule.second);
        rules_total++;
    }

    return rules;
}
std::vector<std::vector<int>> fetch_updates()
{
    std::ifstream filestream("../input.txt");
    if (filestream.fail())
    {
        std::cout << "'input.txt' not found.\n";
        return {};
    }

    std::vector<std::vector<int>> updates;
    std::string line;
    while (std::getline(filestream, line))
    {
        if (line.find(',') == std::string::npos)
            continue;

        std::vector<int> update;
        std::stringstream ss(line);
        std::string s;
        while (std::getline(ss, s, ','))
        {
            update.push_back(std::stoi(s));
        }

        updates.push_back(update);
    }

    return updates;
}