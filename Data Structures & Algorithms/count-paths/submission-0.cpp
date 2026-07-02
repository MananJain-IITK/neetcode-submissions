class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(0, 0, m, n, memo);
    }

   private:
    int dp(int i, int j, int m, int n, vector<vector<int>>& memo) {
        if (i == m-1 && j == n-1) return 1;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int curr = 0;
        if (i < m-1) curr += dp(i + 1, j, m, n, memo);
        if (j < n-1) curr += +dp(i, j + 1, m, n, memo);
        return memo[i][j] = curr;
    }
};
