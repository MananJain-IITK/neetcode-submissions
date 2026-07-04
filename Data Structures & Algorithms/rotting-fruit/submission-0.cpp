class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int fresh = 0;
        int time=0;
        queue<pair<int, int>> que;

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) que.push({i,j});
            }
        }
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!que.empty()){
            auto [r, c] = que.front();
            que.pop();
            time++;
            for(auto& dir: dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr>=0 && nc>=0 && nr<R && nc<C && grid[nr][nc]==1){
                    fresh--;
                    grid[nr][nc] = -1;
                    que.push({nr, nc});
                }
            }
        }
        return (fresh==0)? time: -1;
        // return fresh;
    }
};
