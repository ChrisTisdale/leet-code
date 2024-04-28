#include "Solution.h"

list_node_recursive Solution::reverse_between(ListNode *head, int k) {
    if (!head) {
        return {nullptr, nullptr};
    }

    if (k == 1) {
        return {head, head};
    }

    if (!head->next) {
        return {nullptr, nullptr};
    }

    const auto [new_head, last] = reverse_between(head->next, k - 1);
    if (!new_head || !last) {
        return {nullptr, nullptr};
    }

    head->next = last->next;
    last->next = head;
    return {new_head, head};
}

ListNode *Solution::reverseBetween(ListNode *head, int k) {
    auto current = head;
    ListNode *new_head = nullptr;
    ListNode *last = head;
    while (current) {
        const auto [previous_head, previous_last] = reverse_between(current, k);
        if (!previous_head) {
            break;
        }

        if (!new_head) {
            new_head = previous_head;
        } else {
            last->next = previous_head;
        }

        last = previous_last;
        current = previous_last->next;
    }

    return new_head;
}
