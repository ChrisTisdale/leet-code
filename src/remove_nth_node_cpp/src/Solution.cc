#include "ListNode.h"
#include "Solution.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    return removeNthFromEndInternal(head, n);
}

ListNode* Solution::removeNthFromEndInternal(ListNode* head, int& n) {
    if (!head) {
        --n;
        return nullptr;
    }

    auto res = removeNthFromEndInternal(head->next, n);
    if (n == 0) {
        n = -1;
        return res;
    }

    n = n < 0 ? n : n - 1;
    head->next = res;
    return head;
}