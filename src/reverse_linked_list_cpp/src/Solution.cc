#include "Solution.h"

ListNode* Solution::reverseList(ListNode* head) {
    auto current = head;
    ListNode* previous = nullptr;
    while (current) {
        auto next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}
