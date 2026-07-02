class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        dp(nums, ans, 0, 0);
        return ans;
    }

   private:
    void dp(vector<int>& nums, int& ans, int curr, int idx) {
        for (int i = idx; i < nums.size(); i++) {
            curr ^= nums[i];
            dp(nums, ans, curr, i + 1);
            ans += curr;
            curr ^= nums[i];
        }
    }
};