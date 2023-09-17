#include "Solution.h"

int Solution::romanToInt(std::string s) {
    int result = 0;
    int last = 0;
    for (int i = static_cast<int>(s.length()) - 1; i >= 0; --i) {
        int current;
        switch (s[i])
        {
        case 'M':
            current = 1000;
            break;
        case 'D':
            current = 500;
            break;
        case 'C':
            current = 100;
            break;
        case 'L':
            current = 50;
            break;
        case 'X':
            current = 10;
            break;
        case 'V':
            current = 5;
            break;
        default:
            current = 1;
            break;
        }

        if (current < last) {
            result -= current;
        } else {
            result += current;
        }

        last = current;
    }

    return result;
}
