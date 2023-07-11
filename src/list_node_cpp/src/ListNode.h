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

    ~ListNode() {
        delete next;
    }

    static ListNode* fromVector(const std::vector<int>& input) {
        if (input.empty()) {
            return nullptr;
        }

        auto head = new ListNode(input[0]);
        auto current = head;
        for (std::size_t i = 1; i < input.size(); ++i) {
            current->next = new ListNode(input[i]);
            current = current->next;
        }

        return head;
    }

    const std::size_t length() {
        int count = 0;
        auto current = this;
        while (current) {
            ++count;
            current = current->next;
        }

        return count;
    }

    const std::vector<int> toList() {
        std::vector<int> in;
        auto current = this;
        while (current) {
            in.push_back(current->val);
            current = current->next;
        }

        return in;
    }
private:
};
