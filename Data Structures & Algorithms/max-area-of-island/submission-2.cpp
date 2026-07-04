class Solution {
    int maxi;
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        maxi = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    ans++;
                    dfs(grid, ans, c, r,0);
                }
            }
        }
        return maxi;
    }

   private:
    void dfs(vector<vector<char>>& grid, int& ans, int c, int r, int& curr) {
        if (c < 0 || r < 0 || c >= grid[0].size() || r >= grid.size() || grid[r][c] == '0') return;
        grid[r][c] = '0';
        maxi = max(maxi, ++curr);
        dfs(grid, ans, c - 1, r, curr);
        dfs(grid, ans, c + 1, r, curr);
        dfs(grid, ans, c, r - 1, curr);
        dfs(grid, ans, c, r + 1, curr);
    }
};
