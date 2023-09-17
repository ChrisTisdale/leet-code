#include "Solution.h"
#include <sstream>
#include <string>
#include <vector>

const std::vector<look_up> Solution::look_up_data {
    { 1000, "M" },
    { 900, "CM" },
    { 500, "D" },
    { 400, "CD" },
    { 100, "C" },
    { 90, "XC" },
    { 50, "L" },
    { 40, "XL" },
    { 10, "X" },
    { 9, "IX" },
    { 5, "V" },
    { 4, "IV" },
    { 1, "I" },
};

std::string Solution::intToRoman(int num) {
    std::stringstream ss;
    size_t start = 0;
    while (num) {
        for (; start < look_up_data.size(); ++start) {
            auto data = look_up_data[start];
            if (data.amount > num) {
                continue;
            }

            num -= data.amount;
            ss << data.output;
            break;
        }
    }

    return ss.str();
}
