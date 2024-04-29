#include "ll1.h"
#include "utils.h"
#include <iostream>

void LL1::compute_first()
{
    for (char c : alphabet)
    {
        first[c] = std::unordered_set<char>{c};
    }
    first['#'] = std::unordered_set<char>{'#'};
    bool has_changed = true;
    while (has_changed)
    {
        has_changed = false;
        for (std::unordered_map<char, std::vector<std::string>>::iterator it = rules.begin(); it != rules.end(); ++it)
        {
            for (std::string production : it->second)
            {
                if (!('A' <= production[0] && production[0] <= 'Z'))
                {
                    if (first[it->first].find(production[0]) == first[it->first].end())
                    {
                        has_changed = true;
                        first[it->first].insert(production[0]);
                    }
                }
                else
                {
                    size_t i = 0;
                    for (i = 0; i < production.size(); ++i)
                    {
                        if (insert_different_and_not_lambda(first[it->first], first[production[i]]))
                        {
                            has_changed = true;
                        }
                        if (first[production[i]].find('_') == first[production[i]].end())
                        {
                            break;
                        }
                    }
                    if (i == production.size() && first[it->first].find('_') == first[it->first].end())
                    {
                        has_changed = true;
                        first[it->first].insert('_');
                    }
                }
            }
        }
    }
}

std::unordered_set<char> LL1::compute_first_for_string(const std::string &str)
{
    if (computed_firsts.find(str) != computed_firsts.end())
    {
        return computed_firsts[str];
    }

    if (str.empty())
    {
        return std::unordered_set<char>{};
    }

    if (!('A' <= str[0] && str[0] <= 'Z'))
    {
        return std::unordered_set<char>{str[0]};
    }
    std::unordered_set<char> first_for_given_string = {};

    size_t i;
    for (i = 0; i < str.size(); ++i)
    {
        insert_different_and_not_lambda(first_for_given_string, first[str[i]]);
        if (first[str[i]].find('_') == first[str[i]].end())
        {
            break;
        }
    }
    if (i == str.size())
    {
        first_for_given_string.insert('_');
    }

    // std::cout << "----------------\n"
    //           << str << "\n";

    // for (auto c : first_for_given_string)
    // {
    //     std::cout << c << " ";
    // }
    // std::cout << "\n-----------------\n";

    computed_firsts[str] = first_for_given_string;
    return first_for_given_string;
}
