class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Map: Original Node Address -> Cloned Node Address
        unordered_map<Node*, Node*> oldToNew;

        // 1. First Pass: Create all the cloned nodes (with values only)
        Node* ptr = head;
        while (ptr != nullptr) {
            oldToNew[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        // 2. Second Pass: Connect all the 'next' and 'random' pointers
        ptr = head;
        while (ptr != nullptr) {
            // Because we map pointers to pointers, this automatically 
            // handles NULL safely! If ptr->next is NULL, oldToNew[NULL] is NULL.
            oldToNew[ptr]->next = oldToNew[ptr->next];
            oldToNew[ptr]->random = oldToNew[ptr->random];
            
            ptr = ptr->next; // Move forward safely
        }
        return oldToNew[head];
    }
};