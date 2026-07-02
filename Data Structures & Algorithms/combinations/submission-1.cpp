class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        // for (int i = 1; i <= n; i++) {
        //     curr.push_back(i);
            backtrack(n, k, ans, 1, curr);
        // }
        return ans;
    }

   private:
    void backtrack(int n, int k, vector<vector<int>>& ans, int i, vector<int>& curr) {
        if (curr.size() >= k) {
            ans.push_back(curr);
            return;
        }
        if (i > n) return;
        for(int j=i;j<=(n-(k-curr.size())+1);j++){
        curr.push_back(j);
        backtrack(n, k, ans, j+1, curr);
        curr.pop_back();
        }
    }
};