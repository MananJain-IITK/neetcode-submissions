/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int interval = 1;
        int n = lists.size();
        
        while (interval < n) {
            for (int i = 0; i + interval < n; i += interval * 2) {
                lists[i] = mergeLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
    }

    ListNode* mergeLists(ListNode*& l1, ListNode*& l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            int val1 = ptr1->val;
            int val2 = ptr2->val;

            if (val1 > val2) {
                tail->next = ptr2;
                tail = ptr2;
                ptr2 = ptr2->next;
            } else {
                tail->next = ptr1;
                tail = ptr1;
                ptr1 = ptr1->next;
            }
        }
        if (ptr1 != nullptr) {
            tail->next = ptr1;
        } else {
            tail->next = ptr2;
        }
        return dummy->next;
    }
};
