#pragma once

#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n);
private:
    static std::vector<std::string> generateParenthesisInternal(std::map<int, std::vector<std::string>>& history, int n);
};
