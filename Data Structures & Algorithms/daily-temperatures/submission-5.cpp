class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<pair<int, int>> stk;
        // int j=0;

        for(int i=0; i<n; i++){
            int t= temperatures[i];
            while(!stk.empty() && t>=stk.top().first){
                auto temp = stk.top();
                stk.pop();
                result[temp.second] = (i-temp.second);
            }
            stk.push({t,i});
        }
        return result;
    }
};
