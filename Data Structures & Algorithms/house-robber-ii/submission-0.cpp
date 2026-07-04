class Solution {
public:
    int rob(vector<int>& nums) {
        // nums.push_back(nums[0]);
        vector<int> memo1(nums.size(), -1);
        vector<int> memo2(nums.size(), -1);
        return max(dfs(vector<int>(nums.begin(), nums.end()-1), memo1, 0), dfs(vector<int>(nums.begin()+1, nums.end()), memo2, 0));
    }

    int dfs(vector<int> nums, vector<int>& memo, int i){
        if(i>=nums.size()) return 0;
        if(memo[i]!= -1) return memo[i];
        memo[i] = max(nums[i]+dfs(nums, memo, i+2), dfs(nums, memo, i+1));
        return memo[i];
    }
};
