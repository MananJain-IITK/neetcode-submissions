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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* ptr =head;
        while(ptr != nullptr){
            len++;
            ptr = ptr->next;
        }
        int count = len - n;
        if(count==0){
            return head->next;
        }
        ptr = head;
        while(count >1){
            count--;
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};
