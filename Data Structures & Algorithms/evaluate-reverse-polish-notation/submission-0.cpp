class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        if(tokens.size() == 1) return int(tokens[0]-48);
        for(char c: tokens){
            if(c>=48 && c<=57){
                int num = c-48;
                stk.push(num);
            }else{
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                int res = 0;
                if(c=='+'){
                    res = num1 + num2;
                }else if(c=='-'){
                    res = num1 - num2;
                }else if(c=='*'){
                    res = num1*num2;
                }else if(c=='/'){
                    res = num1/num2;
                }
                stk.push(res);
            } 

        }
        return stk.top();
    }
};
