#pragma once

#include "ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
private:
    static ListNode* removeNthFromEndInternal(ListNode* head, int& n);
};
