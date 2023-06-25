#pragma once

#include <string>
#include <vector>

struct look_up {
    int amount;
    std::string output;

    look_up(const int amount, std::string output) : amount(amount), output(std::move(output)) {
    }
};

class Solution {
public:
    std::string intToRoman(int num);

private:
    static const std::vector<look_up> look_up_data;
};
