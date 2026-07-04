/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){
            return x.start < y.start;
        });
        int ans=1;
        int n = intervals.size();
        for(int i=1; i<n; i++){
            if(isConflict(intervals, i, i)) ans++;
        }
        return ans;
    }

private:
    bool isConflict(vector<Interval>& intervals, int i, int j){
        if(i<=0) return true;
        if(intervals[j].start<intervals[i].end) return isConflict(intervals, i-1, j);
        return false;
    }
};
