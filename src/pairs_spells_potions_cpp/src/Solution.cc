#include "Solution.h"
#include <algorithm>

std::vector<int> Solution::successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
    std::vector<int> counts;
    counts.reserve(spells.size());
    std::sort(potions.begin(), potions.end());
    for (auto s : spells) {
        counts.push_back(search(potions, static_cast<long long>(s), success));
    }

    return counts;
}

int Solution::search(std::vector<int> &potions, long long spell, long long int target) {
    if (potions.empty()) {
        return 0;
    }

    int size = static_cast<int>(potions.size());
    int minI = 0;
    int maxI = size - 1;
    int found = size;
    while (minI <= maxI) {
        int mid = minI + ((maxI - minI) / 2);
        long long res = spell * static_cast<long long>(potions[mid]);
        if (res >= target) {
            maxI = mid - 1;
            found = mid;
        } else {
            minI = mid + 1;
        }
    }

    return static_cast<int>(potions.size() - found);
}
