class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        // for (int i = 0; i < nums.size(); i++) {
        return (dp(nums, sum / 2, 0));
        // }
        // return false;
    }

   private:
    bool dp(vector<int>& nums, int target, int j) {
        if (j == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }
        return dp(nums, target - nums[j], j + 1) || dp(nums, target, j + 1);
    }
};
