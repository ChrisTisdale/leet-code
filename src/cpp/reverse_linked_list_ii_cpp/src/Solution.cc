#include "Solution.h"

ListNode* Solution::reverseBetween(ListNode* head, int left, int right) {
    auto current = head;
    auto start = head;
    ListNode* previous = nullptr;
    const auto headChanged = left <= 1;
    while (--left > 0 && current) {
        --right;
        start = current;
        current = current->next;
    }

    ListNode* end = current;
    while (current && right-- > 0) {
        const auto next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    if (end && end != current) {
        end->next = current;
    }

    if (headChanged) {
        return previous;
    }

    start->next = previous;
    return head;
}
