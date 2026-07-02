class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int sum = 0;
        int ans = n+1;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            if (sum >= target) {
                int curr = r-l+1; 
                sum -= nums[l];
                l++;
                while (sum >= target) {
                    curr--;
                    sum -= nums[l];
                    l++;
                }
                ans=min(ans, curr);
            }
        }
        return ans==n+1?0:ans;
    }
};