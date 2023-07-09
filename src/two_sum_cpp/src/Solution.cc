#include "Solution.h"
#include <unordered_map>

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        auto r = map.find((target - nums[i]));
        if (r != map.end()) {
            return { i, r->second };
        } else {
            map[nums[i]] = i;
        }
    }

    return { };
}
