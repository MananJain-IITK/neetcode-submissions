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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* curr = head;
        int interval = 0;;
        
        while(curr!=nullptr){
            if(isGroup(curr, k)){
                int n = k;
                ListNode* prev = nullptr;
                ListNode* tailTemp = curr;
                while(n!=0){
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                    n--;
                }
                tail->next = prev;
                tail = tailTemp;
            }else{
                tail->next = curr;
                break;
            }
        }
        return dummy->next;
    }

    bool isGroup(ListNode* ptr, int k){
        while(k!=0 && ptr!=nullptr){
            ptr = ptr->next;
            k--;
        }
        if(k!=0) return false;
        else return true;
    }
};
