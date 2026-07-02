#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<int>> ans;
        
        // Two visited matrices to track which ocean can reach which cell
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        
        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;
        
        // 1. MULTI-SOURCE SETUP: Load the coasts into the queues
        for (int r = 0; r < ROWS; r++) {
            pacQueue.push({r, 0});
            pac[r][0] = true;
            
            atlQueue.push({r, COLS - 1});
            atl[r][COLS - 1] = true;
        }
        for (int c = 0; c < COLS; c++) {
            pacQueue.push({0, c});
            pac[0][c] = true;
            
            atlQueue.push({ROWS - 1, c});
            atl[ROWS - 1][c] = true;
        }
        
        // 2. BFS: Flow uphill from both oceans
        bfs(heights, pacQueue, pac, ROWS, COLS);
        bfs(heights, atlQueue, atl, ROWS, COLS);
        
        // 3. Find the intersections!
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }
        
        return ans;
    }

private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited, int ROWS, int COLS) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                // If out of bounds, OR already visited, OR it flows downhill (we want uphill!), skip it
                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || 
                    visited[nr][nc] || heights[nr][nc] < heights[r][c]) {
                    continue;
                }
                
                // Mark visited and push to continue the uphill ripple
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
};