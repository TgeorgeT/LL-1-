#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <unordered_set>

std::vector<std::string> split(const std::string &str, char delim);
bool insert_different_and_not_lambda(std::unordered_set<char> &set1, std::unordered_set<char> &set2);
bool insert_different(std::unordered_set<char> &set1, std::unordered_set<char> &set2);

#endif