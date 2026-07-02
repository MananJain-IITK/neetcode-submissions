class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>currPath;
        backtrack(ans, currPath, nums, 0);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& currPath, vector<int>& nums, int idx){
        ans.push_back(currPath);
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            currPath.push_back(nums[i]);
            backtrack(ans, currPath, nums, i+1);
            currPath.pop_back();
        }
    }
};
