#pragma once

#include <vector>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success);
private:
    static int search(std::vector<int>& potions, long long spell, long long target);
};
