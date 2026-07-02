class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> minHeap;
        vector<vector<int>> ans;
        int n = points.size();
        for(int i=0; i<n; i++){
            double d = pow(points[i][0], 2) + pow(points[i][1], 2);
            minHeap.push({d, i});
        }
        while(k--){
            ans.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        return ans;
    }
};
