#include "Solution.h"
#include <stack>

bool Solution::isValid(std::string s) {
    std::stack<char> stack;
    for (size_t i = 0; i < s.length(); ++i) {
        auto c = s[i];
        switch (c)
        {
        case '{':
        case '(':
        case '[':
            stack.push(c);
            break;
        case '}':
            if (stack.empty() || stack.top() != '{') return false;
            stack.pop();
            break;
        case ')':
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
            break;
        case ']':
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
            break;
        default:
            return false;
        }
    }

    return stack.empty();
}
