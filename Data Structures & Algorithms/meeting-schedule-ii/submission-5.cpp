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
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(),
             [](auto& x, auto& y) { return x.start < y.start; });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans = 1;
        minHeap.push(intervals[0].end);
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < minHeap.top()) {
                ans++;
                minHeap.push(intervals[i].end);
            } else {
                minHeap.pop();
                minHeap.push(intervals[i].end);
            }
        }
        return ans;
    }
};
