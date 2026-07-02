class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int time = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            curr_minpq;

        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                       greater<pair<pair<int, int>, int>>>
            minpq;
        for (int i = 0; i < tasks.size(); i++) {
            vector<int> task = tasks[i];
            minpq.push({{task[0], task[1]}, i});
        }

        while (ans.size() < tasks.size()) {
            while (!minpq.empty() && minpq.top().first.first <= time) {
                curr_minpq.push({minpq.top().first.second, minpq.top().second});
                minpq.pop();
            }
            
            if (!curr_minpq.empty()) {
                time+=curr_minpq.top().first;
                ans.push_back(curr_minpq.top().second);
                curr_minpq.pop();
            }else time=minpq.top().first.first;
        }
        return ans;
    }
};