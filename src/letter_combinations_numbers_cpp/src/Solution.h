#pragma once

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits);

private:
    template<std::size_t S>
    static std::vector<std::string> getLetters(const std::vector<std::string> &data, const char (&input)[S]);
};
