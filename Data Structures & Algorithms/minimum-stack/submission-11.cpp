class MinStack {
public:
    stack<int> s;
    stack<int> minStk;

    MinStack() {}
    
    void push(int val) {
        s.push(val);
        
        // If it's the first element, it's automatically the minimum.
        // Otherwise, the new minimum is the lesser of val or the previous minimum.
        if (minStk.empty()) {
            minStk.push(val);
        } else {
            minStk.push(min(val, minStk.top()));
        }
    }
    
    void pop() {
        // Since both stacks always grow together, they must shrink together.
        s.pop();
        minStk.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};