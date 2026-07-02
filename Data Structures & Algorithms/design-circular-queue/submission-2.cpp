class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    ListNode* start; 
    ListNode* end;   
    int size;        
    int capacity;    

public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        for (int i = 1; i < k; i++) {
            curr->next = new ListNode(-1);
            curr = curr->next;
        }
        curr->next = head; // Close the circle loop structurally

        start = head;
        end = head;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            end = start;
        } else {
            end = end->next;
        }

        end->val = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        // 3. Move front pointer forward and decrement size safely
        start = start->next;
        size--;
        return true;
    }

    int Front() { 
        return isEmpty() ? -1 : start->val; 
    }

    int Rear() { 
        return isEmpty() ? -1 : end->val; 
    }

    bool isEmpty() { 
        return size == 0; 
    }

    bool isFull() { 
        return size == capacity; 
    }
};