class MyStack {
public:
    queue<int> main;
    queue<int> helper;
    MyStack() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        while(main.size()>2){
            helper.push(main.front());
            main.pop();
        }
        int ans = main.front();
        main.pop();
        while(!helper.empty()){
            main.push(helper.front());
            helper.pop();
        }
        return ans;
    }
    
    int top() {
        while(main.size()>1){
            helper.push(main.front());
            main.pop();
        }
        int ans = main.front();
        while(!helper.empty()){
            main.push(helper.front());
            helper.pop();
        }
        return ans;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */