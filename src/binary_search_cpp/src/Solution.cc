#include "Solution.h"
#include <vector>
#include <iostream>

int Solution::search(std::vector<int>& nums, int target) {
    if (nums.size() <= 0) {
        return -1;
    }

    return search(nums, 0, nums.size() - 1, target);
}

int Solution::search(std::vector<int>& nums, int start, int stop, int target) {
    if (start > stop) {
        return -1;
    }

    int loc = start + ((stop - start) / 2);
    if (nums[loc] == target) {
        return loc;
    }

    auto greater = nums[loc] < target;
    auto new_start = greater ? loc + 1 : start;
    auto new_stop = greater ? stop : loc -1;
    return search(nums, new_start, new_stop, target);
}
