#include "utils.h"

std::vector<std::string> split(const std::string &str, char delim)
{
    std::vector<std::string> result;
    size_t start = 0;

    for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, start))
    {
        result.emplace_back(str.begin() + start, str.begin() + found);
        start = found + 1;
    }
    if (start != str.size())
        result.emplace_back(str.begin() + start, str.end());
    return result;
}

bool insert_different_and_not_lambda(std::unordered_set<char> &set1, std::unordered_set<char> &set2)
{
    bool modified = false;
    for (std::unordered_set<char>::iterator it = set2.begin(); it != set2.end(); ++it)
    {
        if (*it != '_' && set1.find(*it) == set1.end())
        {
            set1.insert(*it);
            modified = true;
        }
    }
    return modified;
}

bool insert_different(std::unordered_set<char> &set1, std::unordered_set<char> &set2)
{
    bool modified = false;
    for (std::unordered_set<char>::iterator it = set2.begin(); it != set2.end(); ++it)
    {
        if (set1.find(*it) == set1.end())
        {
            set1.insert(*it);
            modified = true;
        }
    }
    return modified;
}