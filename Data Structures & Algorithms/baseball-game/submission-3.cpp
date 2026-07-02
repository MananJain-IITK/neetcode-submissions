class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int sum=0;
        // int test=1;
        for(string c: operations){
            // if(test--) continue;
            // if(stk.empty()) continue;
            if(c=="+"){
                int top = stk.top();
                stk.pop();
                int newTop = top + stk.top();
                stk.push(top);
                stk.push(newTop);
                sum+=newTop;
            }else if(c=="C"){
                sum-=stk.top();
                stk.pop();
            }else if(c=="D"){
                // sum += 2*stk.top();
                stk.push(2*stk.top());
                sum+=stk.top();
            }else{
                stk.push(stoi(c));
                sum+=stk.top();
                // return stoi(c);
            }
        }
        return sum;
    }
};