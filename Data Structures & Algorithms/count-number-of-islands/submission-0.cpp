class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if(grid[r][c] == '1'){
                    ans++;
                dfs(grid, ans, c, r);
                }
            }
        }
        return ans;
    }

   private:
    void dfs(vector<vector<char>>& grid, int& ans, int c, int r) {
        if (c < 0 || r < 0 || c >= grid[0].size() || r >= grid.size() || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, ans, c - 1, r);
        dfs(grid, ans, c + 1, r);
        dfs(grid, ans, c, r - 1);
        dfs(grid, ans, c, r + 1);
    }
};
