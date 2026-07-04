class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int ROWS = heights.size();
        int COLS = heights[0].size();
        queue<pair<int, int>> que;
        // que.push({0,0});
        int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                que.push({r,c});
                bool isP = false;
                bool isA = false;
                while (!que.empty()) {
                    auto [r, c] = que.front();
                    que.pop();
                    for (auto& dir : dirs) {
                        int nr = r + dir[0];
                        int nc = c + dir[1];
                        if (nr < 0 || nc < 0) isP = true;
                        if (nr >= ROWS || nc >= COLS) isA = true;
                        if (isP && isA){
                            break;
                        }
                        if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                            heights[nr][nc] <= heights[r][c]) {
                            que.push({nr, nc});
                        }
                        
                    }
                }
                if (isP && isA) {
                    vector<int> temp = {r, c};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};