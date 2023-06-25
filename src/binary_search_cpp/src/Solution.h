#pragma once

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target);
private:
    int search(std::vector<int>& nums, int start, int stop, int target);
};
