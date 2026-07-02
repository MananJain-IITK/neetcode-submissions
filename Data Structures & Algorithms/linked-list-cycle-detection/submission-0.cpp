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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> freq;
        ListNode* ptr = head;
        while(ptr != nullptr){
            freq[ptr] ++;
            if(freq[ptr] > 1){
                return true;
            }
            ptr = ptr -> next;
        }
        return false;
    }
};
