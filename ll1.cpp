#ifndef LL1_H
#define LL1_H

#include "ll1.h"
#include "utils.h"
#include <fstream>
#include <iostream>

void LL1::read_grammar(std::string input_file)
{
    std::ifstream file(input_file);

    if (!file.is_open())
    {
        throw std::runtime_error("error_open_file");
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        rules[line[0]] = split(line.substr(3), '|');
        for (char c : line.substr(3))
        {
            if (c != '|' && !('A' <= c && c <= 'Z'))
            {
                alphabet.insert(c);
            }
        }
    }
    file.close();
}

void LL1::print_rules()
{
    std::cout << "rules:\n";
    for (auto it = rules.begin(); it != rules.end(); ++it)
    {
        std::cout << it->first << ": ";
        for (std::string s : it->second)
        {

            std::cout << s << " ";
        }
        std::cout << "\n";
    }
}

void LL1::print_alphabet()
{
    std::cout << "alphabet:\n";
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it)
    {
        std::cout << *(it) << " ";
    }
    std::cout << "\n";
}

void LL1::print_first()
{
    std::cout << "first:\n";
    for (auto it = first.begin(); it != first.end(); ++it)
    {
        std::cout << it->first << ": ";
        for (char c : it->second)
        {

            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}

void LL1::print_follow()
{
    std::cout << "follow:\n";
    for (auto it = follow.begin(); it != follow.end(); ++it)
    {
        std::cout << it->first << ": ";
        for (char c : it->second)
        {

            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}

#endif