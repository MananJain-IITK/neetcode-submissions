class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for(int i=0;i<queries.size();i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        int i=0;
        vector<int> ans(queries.size(), -1);
        for(auto& q: sortedQueries){
            int val = q.first;
            int idx = q.second;

            while(i<intervals.size() && intervals[i][0]<=val){
                minHeap.push({intervals[i][1] - intervals[i][0] +1, intervals[i][1]});
                i++;
            }

            while(!minHeap.empty() && minHeap.top().second<val) minHeap.pop();
            if(!minHeap.empty()) ans[idx] = minHeap.top().first;
        }
        return ans;
    }
};
