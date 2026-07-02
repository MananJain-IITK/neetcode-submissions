class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // ans.push_back({});
        // if(nums.empty()) return ans;
        vector<int> currPath;
        backtrack(ans, nums, 0, currPath);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int>& currPath){
        ans.push_back(currPath);
        for(int i=idx; i<nums.size(); i++){
            currPath.push_back(nums[i]);
            backtrack(ans, nums, i+1,currPath);
            currPath.pop_back();
        }
    }
};
