class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& s : tokens) {
            // Check if the current string token is an operator
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                // First pop gives the RIGHT operand
                int num2 = stk.top(); 
                stk.pop();
                
                // Second pop gives the LEFT operand
                int num1 = stk.top(); 
                stk.pop();
                
                int res = 0;
                if (s == "+") res = num1 + num2;
                else if (s == "-") res = num1 - num2; // Order critical!
                else if (s == "*") res = num1 * num2;
                else if (s == "/") res = num1 / num2; // Order critical!
                
                stk.push(res);
            } 
            // If it's not an operator, it must be a number
            else {
                // stoi automatically converts positive/negative multi-digit strings to int
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};