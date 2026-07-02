class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        vector<vector<int>> memo(nums.size(), vector<int>(sum/2+1, -1));
        return (dp(nums, memo, sum / 2, 0));
    }

   private:
    bool dp(vector<int>& nums, vector<vector<int>>& memo, int target, int j) {
        if (j == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }
        if(memo[j][target]!=-1) return memo[j][target]==0? false:true;
        memo[j][target] =  dp(nums, memo, target - nums[j], j + 1) || dp(nums, memo, target, j + 1);
        return memo[j][target];
    }
};
