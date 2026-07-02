class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 0) que.push({i, j});
            }
        }
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();

            for (auto dir : dirs) {
                int nr = r+dir[0];
                int nc = c+dir[1];
                if (nr >= 0 && nc >= 0 && nr < R && nc < C && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1;
                    que.push({nr, nc});
                }
            }
        }
    }
};
