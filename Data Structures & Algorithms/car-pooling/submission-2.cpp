class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int count = 0;
        int time = 0;
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                       greater<pair<pair<int, int>, int>>>
            minHeap;
        for (const vector<int>& trip : trips) {
            minHeap.push({{trip[1], trip[2]}, trip[0]});
        }
        while (!minHeap.empty()) {
            int start = minHeap.top().first.first;
            int end = minHeap.top().first.second;
            int curr = minHeap.top().second;
            minHeap.pop();
            if (time > start)
                count += curr;
            else
                count = curr;
            if (count > capacity) return false;

            if (time < end) {
                count = curr;
            }
                time = end;
            
        }
        return true;
    }
};