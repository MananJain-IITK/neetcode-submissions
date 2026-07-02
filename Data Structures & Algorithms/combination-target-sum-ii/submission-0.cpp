class Solution {
public:
    int t;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currPath;
        int currSum = 0;
        this->t = target;
        backtrack(ans, candidates, currPath, currSum, 0);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& currPath, int currSum, int idx){
        if(currSum == t){
            ans.push_back(currPath);
            return;
        }else if(currSum > t) return;
        
        for(int i=idx; i<candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            currPath.push_back(candidates[i]);
            currSum+=candidates[i];
            backtrack(ans, candidates, currPath, currSum, i+1);
            currPath.pop_back();
            currSum-=candidates[i];
        }
    }
};
