class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1, -1);
        return dfs(nums, target , memo);
    }

   private:
    int dfs(vector<int>& nums, int target, vector<int>& memo) {
        if(target == 0) {
            return 1;
        }
        if(target<0) return 0;
        if(memo[target]!=-1) {
            return memo[target];
            
        }
        int ans=0;
        for(int i=0;i<nums.size();i++) ans += dfs(nums, target - nums[i], memo);
        
        return memo[target] = ans;
    }
};