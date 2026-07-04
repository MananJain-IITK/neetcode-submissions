class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int  l =0;
        int r = n-1;
        int ans = min(heights[r], heights[l]) * (l-r);
        while(l<r){
        if(heights[l] >= heights[r]){
            r--;
        }else{
            l++;
        }
        int temp_ans = min(heights[r], heights[l]) * (r-l);
        ans = max(temp_ans, ans);
        }
        return ans;
    }
};
