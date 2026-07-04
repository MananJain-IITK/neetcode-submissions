class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> stair;
        stair.push({heights[0],0});
        for(int i = 1; i<n; i++){
            int height = heights[i];
            int area = 0;
            if(height<stair.top().first){
                auto temp = stair.top();
                int area = temp.first;
                stair.pop();
                while(stair.top().first!=temp.first){
                    area += temp.first;
                    stair.pop();
                }
            }
            stair.push({height[i], i}),
            maxArea = max(area, maxArea);
        }
        while(!stair.empty()){
            auto temp = stair.top();
            stair.pop();
            maxArea = max(maxArea, temp.first*(temp.second - stair.top().second + 1));
        }
        return maxArea;
    }
};