class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> tracker;
        stack<int> ts;
        int n = position.size();
        for(int i=0; i<n; i++){
            tracker.push_back({position[i], speed[i]});
        }
        sort(tracker.rbegin(), tracker.rend());
        for(int i=0; i<n; i++){
            int time = (target - tracker[i].first)/tracker[i].second;
            if(!ts .empty()&& ts.top()>=time){
                ts.pop();
            }
            ts.push(time);
        }
        return ts.size();
    }
};
