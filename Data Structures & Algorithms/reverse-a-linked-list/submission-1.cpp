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
    ListNode* reverseList(ListNode* head) {
        // if((head->next == nullptr) || head == nullptr) return head;
        ListNode* prev = nullptr;
        // ListNode* forw = nullptr;
        while(head != nullptr){
            ListNode* forw = head->next;
            head->next = prev;
            prev = head;
            head = forw;
        }
        return prev;
    }
};
