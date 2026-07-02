class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> row(c, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0) {
                    if (j == 0)
                        row[j] = grid[i][j];
                    else
                        row[j] = row[j - 1] + grid[i][j];
                } else if (j > 0)
                    row[j] = grid[i][j] + min(row[j], row[j - 1]);
                else
                    row[j] += grid[i][j];
            }
        }
        return row[c - 1];
    }
};