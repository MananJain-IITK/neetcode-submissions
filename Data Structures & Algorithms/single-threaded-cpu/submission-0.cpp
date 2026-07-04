class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> minpq;
        for(int i=0; i<tasks.size();i++){
            vector<int> task = tasks[i];
            minpq.push({{task[0],task[1]},i});
        }

        while(!minpq.empty()){
            pair<pair<int,int>,int> temp = minpq.top();
            ans.push_back(minpq.top().second);
            minpq.pop();
            while(!minpq.empty() && minpq.top().first.first==temp.first.first){
                pair<pair<int,int>,int> temp1 = minpq.top();
                temp1.first.first++;
                minpq.pop();
                minpq.push(temp1);
            }
        }
        return ans;
    }
};