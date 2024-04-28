#include "Solution.h"

ListNode *Solution::mergeKLists(std::vector<ListNode *> &lists) {
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    while (!lists.empty()) {
        size_t min_index = 0;
        ListNode *min = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            const auto list = lists[i];
            if (list && (!min || list->val < min->val)) {
                min = list;
                min_index = i;
            }
        }

        if (!min) {
            return head;
        }

        if (min->next) {
            const auto next = min->next;
            lists[min_index] = next;
        } else {
            lists.erase(lists.begin() + min_index);
        }

        if (!current) {
            min->next = nullptr;
            head = current = min;
        } else {
            min->next = nullptr;
            current->next = min;
            current = min;
        }
    }

    return head;
}
