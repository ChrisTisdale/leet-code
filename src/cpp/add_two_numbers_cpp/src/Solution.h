#pragma once

#include "ListNode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

private:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry);
};
