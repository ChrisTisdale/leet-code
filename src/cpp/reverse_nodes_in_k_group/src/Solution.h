#pragma once
#include "ListNode.h"

struct list_node_recursive {
    ListNode *head;
    ListNode *last;
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int k);

private:
    static list_node_recursive reverse_between(ListNode *head, int k);
};
