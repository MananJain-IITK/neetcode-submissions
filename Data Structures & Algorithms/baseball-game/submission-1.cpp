class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int sum=0;
        for(string c: operations){
            // if(stk.empty()) continue;
            if(c=="+"){
                stk.push(sum);
                sum += sum;
            }else if(c=="C"){
                sum-=stk.top();
                stk.pop();
            }else if(c=="D"){
                sum += 2*stk.top();
                stk.push(2*stk.top());
            }else{
                stk.push(stoi(c));
                sum+=stoi(c);
            }
        }
        return sum;
    }
};