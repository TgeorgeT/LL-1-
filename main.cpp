#include "ll1.h"
#include "utils.h"
#include <iostream>

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

    std::cout << ll1.check("a*a#") << "\n";
}