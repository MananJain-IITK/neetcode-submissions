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
    void reorderList(ListNode* head) {
        // ListNode* lastNode = head;
        ListNode* ptr = head;
        int n = 0;

        while(ptr!= nullptr){
            n++;
            ptr = ptr->next;
        }
        int half = (n+1)/2;
        ListNode* head2 = head;
        while(half!=0){
            half--;
            ListNode* temp = head2;
            head2 = head2->next;
            if(half == 0){
                temp -> next = nullptr;
            }
        }
        ListNode* frw = head;
        ListNode* prev = nullptr;
        while(head2 != nullptr){
            frw = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = frw;
        }
        head2 = prev;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head2;
        
        while(ptr2 != nullptr){
            ListNode* temp1 = ptr1->next;
            ListNode* temp2 = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = temp1;

            ptr1 = temp1;
            ptr2 = temp2;
        }
        // head2 -> next = nullptr;
    }
};
