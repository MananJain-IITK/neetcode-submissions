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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while(ptr1!=nullptr){
            n1++;
            ptr1 = ptr1->next;
        }
        while(ptr2!=nullptr){
            n2++;
            ptr2 = ptr2->next;
        }
        
        if(n1<n2) swap(l1,l2);
        ptr1 = l1;
        ptr2 = l2;
        int carry = 0;
        ListNode* prev = l1;
        while(ptr2!=nullptr){
            prev = ptr1;
            int newVal = (ptr1->val + ptr2->val) + carry;
            ptr1->val = newVal%10;
            carry = (newVal)/10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(carry!=0){
            while(ptr1!=nullptr){
            int newVal = (ptr1->val) + carry;
            ptr1->val = newVal%10;
            carry = (newVal)/10;
            ptr1 = ptr1->next;
            }
            if(carry!=0){
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
            }
        }

        return l1;
    }
};
