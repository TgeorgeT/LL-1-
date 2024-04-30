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
    int cnt = 0;
    std::cout << "rules:\n";
    for (auto &p : rules)
    {
        std::cout << p.first << ": ";
        for (std::string s : p.second)
        {
            cnt++;
            std::cout << cnt << "->" << s << " ";
        }
        std::cout << "\n";
    }
}

void LL1::print_alphabet()
{
    std::cout << "alphabet:\n";
    for (char c : alphabet)
    {
        std::cout << c << " ";
    }
    std::cout << "\n";
}

void LL1::print_first()
{
    std::cout << "first:\n";
    for (auto &p : first)
    {
        std::cout << p.first << ": ";
        for (char c : p.second)
        {

            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}

void LL1::print_follow()
{
    std::cout << "follow:\n";
    for (auto &p : follow)
    {
        std::cout << p.first << ": ";
        for (char c : p.second)
        {

            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}

void LL1::print_table()
{
    std::cout << "table:\n";
    for (auto p1 : table)
    {
        std::cout << p1.first << ": ";
        for (auto p2 : p1.second)
        {
            std::cout << p2.first << "->" << p2.second.first << ", " << p2.second.second << "| ";
        }
        std::cout << "\n";
    }
}

#endif