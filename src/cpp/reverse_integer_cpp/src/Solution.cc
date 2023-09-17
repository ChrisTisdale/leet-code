#ifdef _WIN32
#include <climits>
#endif
#include "Solution.h"

#ifdef _WIN32
constexpr int max_mul = INT_MAX / 10;
constexpr int max_u_mul = INT_MIN / 10;
#endif

int Solution::reverse(int x) {
    int result = 0;

    while (x) {
#ifdef _WIN32
        if (result > 0 ? result > max_mul : result < max_u_mul) {
            return 0;
        }

        result *= 10;
        const int adder = x % 10;
        const int max = x > 0 ? INT_MAX - adder : INT_MIN - adder;
        if (max > 0 ? result > max : result < max) {
            return 0;
        }

        result += adder;
#else
        if (__builtin_smul_overflow(result, 10, &result)) {
            return 0;
        } else if (__builtin_sadd_overflow(result, x % 10, &result)) {
            return 0;
        }
#endif

        x /= 10;
    }
    
    return result;
}
