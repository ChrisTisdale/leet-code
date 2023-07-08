#pragma once
#include <vector>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next) : val(x), next(next) {
    }

    std::size_t length() {
        return next ? 1 + next->length() : 1;
    }

    std::vector<int> toList() {
        std::vector<int> in;
        return toList(std::move(in));
    }
private:
    std::vector<int> toList(std::vector<int> input) {
        input.push_back(val);
        return next ? next->toList(std::move(input)) : std::move(input);
    }
};
