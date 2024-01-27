#include "Solution.h"

std::vector<std::string> Solution::generateParenthesis(int n) {
    std::map<int, std::vector<std::string>> history;
    return generateParenthesisInternal(history, n);
}

std::vector<std::string> Solution::generateParenthesisInternal(std::map<int, std::vector<std::string>>&history, int n) {
    std::vector<std::string> result;
    if (n == 0) {
        return result;
    }

    if (n == 1) {
        result.emplace_back("()");
        history.insert_or_assign(n, result);
        return result;
    }

    if (const auto found = history.find(n); found != history.end()) {
        return found->second;
    }

    for (int i = 0; i < n; ++i) {
        std::vector<std::string> current;
        auto previous = generateParenthesisInternal(history, i == 0 ? n - 1 : n - i);
        for (auto c: previous) {
            if (i == 0) {
                c.insert(0, "()");
                current.push_back(c);
            }
            else {
                c.insert(0, "(");
                c.push_back(')');
                current.push_back(c);
            }
        }

        previous = generateParenthesisInternal(history, n - (n - i) - 1);
        for (const auto&c: current) {
            if (previous.empty()) {
                result.push_back(c);
            }
            else {
                for (const auto&p: previous) {
                    result.push_back(c + p);
                }
            }
        }
    }

    history.insert_or_assign(n, result);
    return result;
}
