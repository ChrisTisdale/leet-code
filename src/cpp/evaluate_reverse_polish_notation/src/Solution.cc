#include <stack>

#include "Solution.h"

int Solution::evalRPN(std::vector<std::string>&tokens) {
    std::stack<int> values;
    for (const auto&token: tokens) {
        if (token.length() > 1) {
            values.push(std::stoi(token));
            continue;
        }

        switch (token[0]) {
            case '+': {
                const auto r = values.top();
                values.pop();
                const auto l = values.top();
                values.pop();
                values.push(l + r);
                break;
            }
            case '*': {
                const auto r = values.top();
                values.pop();
                const auto l = values.top();
                values.pop();
                values.push(l * r);
                break;
            }
            case '-': {
                const auto r = values.top();
                values.pop();
                const auto l = values.top();
                values.pop();
                values.push(l - r);
                break;
            }
            case '/': {
                const auto r = values.top();
                values.pop();
                const auto l = values.top();
                values.pop();
                values.push(l / r);
                break;
            }
            default: {
                values.push(std::stoi(token));
                break;
            }
        }
    }

    return values.empty() ? 0 : values.top();
}
