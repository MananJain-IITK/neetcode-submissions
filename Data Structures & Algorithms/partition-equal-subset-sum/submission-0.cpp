class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++) {
            if (dp(nums, sum / 2, i)) return true;
        }
        return false;
    }

   private:
    bool dp(vector<int>& nums, int target, int j) {
        if (nums[j] == target)
            return true;
        else if (nums[j] > target)
            return false;
        for (int i = j + 1; i < nums.size(); i++) {
            return dp(nums, target - nums[i], i);
        }
        return true;
    }
};
