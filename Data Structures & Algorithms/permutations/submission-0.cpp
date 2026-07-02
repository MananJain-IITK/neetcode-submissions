class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        vector<int> currPath;
        backtrack(ans, currPath, nums, freq);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& currPath, vector<int>& nums, unordered_map<int, int>& freq){
        if(currPath.size() == nums.size()){
            ans.push_back(currPath);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]] == 1) continue;
            freq[nums[i]] = 1;
            currPath.push_back(nums[i]);
            backtrack(ans, currPath, nums, freq);
            freq[nums[i]] = 0;
            currPath.pop_back();
        }
    }
};
