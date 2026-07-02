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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        // ListNode* prev = dummy;
        ListNode* leftNode = head;
        ListNode* prev = dummy;
        for(int i=1;i<left;i++){
            prev = leftNode;
            leftNode = leftNode->next;
        }
        ListNode* rightNode = leftNode;
        for(int i=left;i<right;i++){
            rightNode = rightNode->next;
        }
        ListNode* nextNode = rightNode->next;
        reverse(leftNode,rightNode);
        prev->next = rightNode;
        leftNode->next = nextNode;
        return dummy->next;
        
    }
private:
    void reverse(ListNode* left, ListNode* right){
        ListNode* curr = left;
        ListNode* prev = nullptr;
        while(curr!=right){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }
        right->next = prev;
    }
};