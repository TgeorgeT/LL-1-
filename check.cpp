#include "ll1.h"
#include <deque>

std::string LL1::check(const std::string &s)
{
    std::deque<char> symbol_stack;
    std::deque<char> input_stack;
    std::string output = "";

    symbol_stack.push_back('#');
    symbol_stack.push_back('S');

    for (int i = s.size() - 1; i >= 0; --i)
    {
        input_stack.push_back(s[i]);
    }

    while (!(symbol_stack.back() == '#' && input_stack.back() == '#'))
    {
        if ('A' <= symbol_stack.back() && symbol_stack.back() <= 'Z')
        {
            if (table[symbol_stack.back()][input_stack.back()].first == "error")
            {
                return "error";
            }
            char top = symbol_stack.back();
            symbol_stack.pop_back();
            output += std::to_string(table[top][input_stack.back()].second);
            std::string symbols_to_append = table[top][input_stack.back()].first;

            for (int i = symbols_to_append.size() - 1; i >= 0; --i)
            {
                if (symbols_to_append[i] != '_')
                {
                    symbol_stack.push_back(symbols_to_append[i]);
                }
            }
            continue;
        }

        if (symbol_stack.back() != input_stack.back())
        {
            return "error";
        }

        symbol_stack.pop_back();
        input_stack.pop_back();
    }

    return output;
}