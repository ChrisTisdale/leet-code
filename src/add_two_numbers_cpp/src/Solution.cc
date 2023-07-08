#include "Solution.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addTwoNumbers(l1, l2, 0);
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2, const int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr;
    }

    if (l1 == nullptr && l2 == nullptr) {
        return new ListNode(carry);
    }

    if (l1 == nullptr) {
        if (carry == 0) {
            return l2;
        }

        const int res = l2->val + carry;
        return new ListNode(res % 10, addTwoNumbers(l1, l2->next, res / 10));
    }

    if (l2 == nullptr) {
        if (carry == 0) {
            return l1;
        }

        const int res = l1->val + carry;
        return new ListNode(res % 10, addTwoNumbers(l1->next, l2, res / 10));
    }

    const int res = l1->val + l2->val + carry;
    return new ListNode(res % 10, addTwoNumbers(l1->next, l2->next, res / 10));
}
