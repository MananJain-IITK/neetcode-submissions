class Solution {
    int maxi;
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxi=0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    int ans = 0;
                    dfs(grid, ans, c, r);
                }
            }
        }
        return maxi;
    }

   private:
    void dfs(vector<vector<int>>& grid, int& ans, int c, int r) {
        if (c < 0 || r < 0 || c >= grid[0].size() || r >= grid.size() || grid[r][c] == 0) return;
        grid[r][c] = 0;
        ans++;
        maxi = max(maxi,ans);
        dfs(grid, ans, c - 1, r);
        dfs(grid, ans, c + 1, r);
        dfs(grid, ans, c, r - 1);
        dfs(grid, ans, c, r + 1);
    }
};
