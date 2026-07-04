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
        if ( j > nums.size() - 1 || nums[j] > target)
            return false;
        if (nums[j] == target)
            return true;
        return dp(nums, target - nums[j], j + 1) || dp(nums, target, j + 1);
    }
};
