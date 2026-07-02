class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        this->prefix = matrix;
        for(int j=0;j<matrix.size();j++){
            int sum=0;
            for(int i=0; i<matrix[0].size(); i++){
                sum += prefix[j][i];
                prefix[j][i] = sum;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans= 0;
        for(int i=row1; i<=row2; i++){
            if(col1>0){
            ans+= prefix[i][col2] -prefix[i][col1-1];
            }
            else{
                ans+= prefix[i][col2];
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */