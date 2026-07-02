class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<pair<int, int>> zeroIdx;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(matrix[i][j]==0) zeroIdx.push_back({i,j});
            }
        }
        for(pair<int, int> idx: zeroIdx){
            int r = idx.first;
            int c = idx.second;
            for(int i=0; i<COLS; i++){
                matrix[r][i] = 0;
            }
            for(int i=0; i<ROWS; i++){
                matrix[i][c] = 0;
            }
        }
    }
};
