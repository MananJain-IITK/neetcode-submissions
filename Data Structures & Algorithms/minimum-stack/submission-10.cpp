class MinStack {
public:
    stack<int> s;
    stack<int> minStk;
    int minNum = -1;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minStk.empty()){
            minNum = val;
             minStk.push(minNum);
            //  return;
        }
        minNum = min(val, minNum);
        if(minStk.top() == val){
            minStk.push(val);
        }
        else if(minNum != minStk.top()){
            minStk.push(minNum);
        }
    }
    
    void pop() {
        if(s.top() == minStk.top()){
            minStk.pop();
        }
        s.pop();

    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
