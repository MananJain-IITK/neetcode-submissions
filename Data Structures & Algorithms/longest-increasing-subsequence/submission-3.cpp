class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> memo(n, INT_MIN);
        memo[n - 1] = 1;
        int ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, dp(memo, nums, i));
        }
        return ans;
    }

   private:
    int dp(vector<int>& memo, vector<int> nums, int i) {
        if (i >= nums.size()) return 1;
        if (memo[i] != INT_MIN) return memo[i];
        int temp = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                temp = max(temp, 1 + dp(memo, nums, j));
                
            }
        }
        memo[i] = temp;
        return memo[i];
    }
};
