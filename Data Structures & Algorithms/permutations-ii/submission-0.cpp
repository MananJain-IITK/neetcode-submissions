class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(ans, nums, 0);
        return ans;
    }

   private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i ; j < nums.size(); ++j) {
            if(j>i&&nums[i]==nums[j]) continue;
            swap(nums[i], nums[j]);
            backtrack(ans, nums, i+1);
        }
        for(int j=nums.size()-1;j>=i;j--){
            swap(nums[i],nums[j]);
        }
    }
};