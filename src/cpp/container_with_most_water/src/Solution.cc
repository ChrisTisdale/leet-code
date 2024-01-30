#include <algorithm>

#include "Solution.h"

int Solution::maxArea(std::vector<int>&height) {
    std::size_t left = 0;
    std::size_t right = height.size() - 1;
    int max = INT_MIN;
    while (left < right) {
        const auto l = height[left];
        const auto r = height[right];
        max = std::max(max, std::min(l, r) * static_cast<int>(right - left));

        if (l < r) {
            ++left;
        }
        else {
            --right;
        }
    }

    return max;
}
