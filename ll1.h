#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class LL1
{
private:
    std::unordered_map<char, std::vector<std::string>> rules;
    std::unordered_map<char, std::unordered_set<char>> first, follow;
    std::unordered_map<std::string, std::unordered_set<char>> computed_firsts;
    std::unordered_set<char> alphabet;

public:
    LL1() = default;
    void read_grammar(std::string input_file);
    void print_rules();
    void print_alphabet();
    void compute_first();
    void print_first();
    void compute_follow();
    std::unordered_set<char> compute_first_for_string(const std::string &str);
    void print_follow();
};