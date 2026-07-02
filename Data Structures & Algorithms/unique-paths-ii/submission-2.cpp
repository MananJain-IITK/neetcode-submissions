class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        vector<int> memo(obstacleGrid[0].size(), 0);

        memo[0] = 1;
        // for(int i=0;i<obstacleGrid[0].size();i++) if(obstacleGrid[0][i]==1) for(int
        // j=i;j<obstacleGrid[0].size();j++)memo[j]=0;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    memo[j] = 0;
                    continue;
                }else if(j>0)
                memo[j] = memo[j] + memo[j - 1];
            }
        }
        return memo[obstacleGrid[0].size() - 1];
    }
};