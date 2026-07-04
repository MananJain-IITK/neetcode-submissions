class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        for(int i=1; i<intervals.size();i++){
            if(intervals[i][0]<=intervals[i-1][1]){
                intervals[i][0] = min(intervals[i][0], intervals[i-1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                intervals.erase(intervals.begin()+i-1);
                i--;
                res++;
            }
        }
        return res-1;
    }
};
