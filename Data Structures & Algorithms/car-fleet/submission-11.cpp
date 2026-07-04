class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> tracker;
        stack<double> ts;
        int n = position.size();
        for(int i=0; i<n; i++){
            tracker.push_back({position[i], speed[i]});
        }
        sort(tracker.rbegin(), tracker.rend());
        for(int i=0; i<n; i++){
            double time = (double)(target - tracker[i].first )/tracker[i].second;
            if(ts .size()>=2&& ts.top()>=time){
                continue;   
            }
            ts.push(time);
        }
        return ts.size();
    }
};
