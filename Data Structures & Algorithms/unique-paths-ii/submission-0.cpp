class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> memo(obstacleGrid[0].size(),1);
        for(int i=0;i<obstacleGrid[0].size();i++) if(obstacleGrid[0][i]==1) memo[i]=0;
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j]==1){
                    memo[j]=0;
                    continue;
                }
                memo[j] = memo[j] + memo[j-1];
            }
        }
        return memo[obstacleGrid[0].size()-1];
    }
};