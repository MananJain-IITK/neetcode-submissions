class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> res;
        for(int query: queries){
            int ans=INT_MAX;
            for(int i=0; i<intervals.size(); i++){
                if(intervals[i][1]>=query && intervals[i][0]<=query){
                    ans = min(intervals[i][1] - intervals[i][0] + 1, ans);
                }
            }
            if(ans==INT_MAX) res.push_back(-1);
            else res.push_back(ans);
        }
        return res;
    }
};
