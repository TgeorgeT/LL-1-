#include "ll1.h"
#include "utils.h"
#include <iostream>
#include <fstream>

int main()
{
    LL1 ll1;
    ll1.read_grammar("input.txt");
    ll1.print_rules();
    ll1.print_alphabet();

    ll1.compute_first();
    ll1.print_first();

    ll1.compute_follow();
    ll1.print_follow();

    if (!ll1.compute_table())
    {
        std::cout << "Grammar is not LL\n";
        return 0;
    }
    ll1.print_table();

    std::ifstream words_file("words.txt");
    std::string line;

    while (std::getline(words_file, line))
    {
        std::cout << ll1.check(line) << "\n";
    }
}