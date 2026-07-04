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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* prev1 = nullptr;
       while(ptr1!=nullptr && ptr2!=nullptr){
            if(ptr1->val <= ptr2->val){
                if(ptr1->next != nullptr){
                    prev1 = ptr1;
                    ptr1 = ptr1->next;
                }else{
                    while(ptr2 != nullptr){
                        ptr1->next = ptr2;
                        ptr2 = ptr2->next;
                    }
                    break;
                     
                }
            }else{
                if(prev1!=nullptr)prev1->next = ptr2;
                else list1 = ptr2;
                // else list1 = ptr2;
                ListNode* temp = ptr2->next;
                ptr2->next = ptr1;
                ptr2 = temp;
            }
       }
       return list1;
    }
};
