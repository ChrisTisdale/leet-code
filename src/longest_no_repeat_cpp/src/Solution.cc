#include "Solution.h"
#include <algorithm>

int Solution::lengthOfLongestSubstring(std::string s) {
    int count = 0;
    int max_value = 0;
    int start = 0;
    unsigned int data[8] = { };

    for (int i = 0; i < s.length(); ++i) {
        auto cast = static_cast<unsigned int>(s[i]);
        auto bin = (cast / 32);
        auto check = cast % 32;
        if (data[bin] & (1 << check)) {
            for (int j = start; j < s.length(); ++j) {
                auto c2 = static_cast<unsigned int>(s[j]);
                auto bin2 = (c2 / 32);
                auto c3 = c2 % 32;
                data[bin2] ^= 1 << c3;
                start += 1;
                count -= 1;
                if (s[j] == s[i]) {
                    break;
                }
            }
        }

        data[bin] |= 1 << check;
        count += 1;
        max_value = std::max(count, max_value);
    }

    return max_value;
}
