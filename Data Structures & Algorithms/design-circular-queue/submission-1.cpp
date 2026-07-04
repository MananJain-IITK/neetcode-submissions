
class MyCircularQueue {
   private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

   public:
    ListNode* start;
    ListNode* end;
    MyCircularQueue(int k) {
        ListNode* head = new ListNode(-1);
        start = head;
        end = head;
        ListNode* curr = head;
        for (int i = 1; i < k + 1; i++) {
            ListNode* temp = new ListNode(-1);
            curr->next = temp;
            curr = temp;
        }
        curr->next = head;
    }

    bool enQueue(int value) {
        if(end==start) end->val=value;
        if (end->next == start) return false;
        end = end->next;
        end->val = value;

        return true;
    }

    bool deQueue() {
        start->val = -1;
        start = start->next;
        return true;
    }

    int Front() { return start->val; }

    int Rear() { return end->val; }

    bool isEmpty() {
        if (start == end) return true;
        return false;
    }

    bool isFull() {
        if (end->next == start) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */