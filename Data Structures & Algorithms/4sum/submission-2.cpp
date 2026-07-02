class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i -1]) continue;
            long long target1 = (long long)target - nums[i];
            vector<vector<int>> curr = threeSum(nums, target1, i + 1);
            for (vector<int> temp : curr) {
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }

   private:
    vector<vector<int>> threeSum(vector<int>& nums, long long target, int idx) {
        vector<vector<int>> ans;
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            long long target1 = target - nums[i];
            vector<vector<int>> curr = twoSum(nums, target1, i + 1);
            for (vector<int> temp : curr) {
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int idx) {
        vector<vector<int>> ans;
        int l = idx, r = nums.size() - 1;
        while (l < r) {
            long long sum = nums[l] + nums[r];
            if (sum == target) {
                ans.push_back({nums[l], nums[r]});
                r--;
                l++;
                while(l<r && nums[l]==nums[l-1])l++;
                while(l<r && nums[r]==nums[r+1])r--;
            } else if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return ans;
    }
};