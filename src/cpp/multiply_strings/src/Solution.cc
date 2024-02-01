#include "Solution.h"
#include <ranges>
#include <vector>

std::string Solution::multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    std::vector digits(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            digits[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            digits[i + j] += digits[i + j + 1] / 10;
            digits[i + j + 1] %= 10;
        }
    }

    std::string result;
    for (const auto value : digits | std::ranges::views::drop_while([](const int x) { return x == 0; })) {
        result += std::to_string(value);
    }

    return result;
}
