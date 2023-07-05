#include "Solution.h"

int Solution::reverse(int x) {
    int result = 0;
    while (x) {
        if (__builtin_smul_overflow(result, 10, &result)) {
            return 0;
        } else if (__builtin_sadd_overflow(result, x % 10, &result)) {
            return 0;
        }

        x /= 10;
    }
    
    return result;
}
