class Solution {
public:
    int t;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->t = target;
        vector<vector<int>> ans;
        vector<int> currPath;
        backtrack(ans, nums, currPath, 0, 0);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& currPath, int currSum, int idx){
        if(currSum==t) ans.push_back(currPath);
        else if (currSum>t)return;

        // for(int i=idx; i<nums.size(); i++){
            for(int j=idx; j<nums.size(); j++){
                currPath.push_back(nums[j]);
                currSum += nums[j];
                backtrack(ans, nums, currPath, currSum, j);
                currSum -= nums[j];
                currPath.pop_back();
            }
            // currPath.clear();
            idx++;
        // }
    }
};
