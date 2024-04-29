#include "ll1.h"
#include "utils.h"

void LL1::compute_follow()
{
    follow['S'] = std::unordered_set<char>{'#'};

    bool has_changed = true;
    while (has_changed)
    {
        has_changed = false;
        for (std::unordered_map<char, std::vector<std::string>>::iterator it = rules.begin(); it != rules.end(); ++it)
        {
            for (std::string production : it->second)
            {
                for (size_t i = 0; i < production.length(); i++)
                {
                    if ('A' <= production[i] && production[i] <= 'Z')
                    {
                        if (i == production.length() - 1)
                        {
                            if (insert_different(follow[production[i]], follow[it->first]))
                            {
                                has_changed = 1;
                            }
                        }
                        else
                        {
                            std::unordered_set<char> computed_first = std::move(compute_first_for_string(production.substr(i + 1)));
                            if (insert_different_and_not_lambda(follow[production[i]], computed_first))
                            {
                                has_changed = 1;
                            }
                            if (computed_first.find('_') != computed_first.end() && insert_different(follow[production[i]], follow[it->first]))
                            {
                                has_changed = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}