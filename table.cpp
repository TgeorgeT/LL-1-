#include "ll1.h"
#include "utils.h"
#include <iostream>

std::unordered_set<char> LL1::first_follow(const std::string &str, std::unordered_set<char> &f)
{
    std::unordered_set<char> res = compute_first_for_string(str);
    if (res.find('_') != res.end())
    {
        if (f.find('_') != f.end())
        {
            insert_different(res, f);
        }
        else
        {
            res.erase('_');
            insert_different_and_not_lambda(res, f);
        }
    }
    return res;
}

bool LL1::compute_table()
{
    int cnt = 0;
    for (const std::pair<char, std::vector<std::string>> rule : rules)
    {
        for (const std::string &production : rule.second)
        {
            std::unordered_set<char> symbols = std::move(first_follow(production, follow[rule.first]));
            ++cnt;
            for (char c : symbols)
            {
                if (table[rule.first].find(c) != table[rule.first].end())
                {
                    return false;
                }
                table[rule.first][c] = {production, cnt};
            }
        }

        for (char c : alphabet)
        {
            if (table[rule.first].find(c) == table[rule.first].end())
            {
                table[rule.first][c] = {"error", -1};
            }
        }
    }
    return true;
}