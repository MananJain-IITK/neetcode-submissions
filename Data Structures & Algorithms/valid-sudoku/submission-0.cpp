class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int columns[9] = {0};
        int squares[9] = {0};

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char x = board[r][c];
                if(x != '.'){
                    int val = x - '1';

                    if((rows[r] & (1<<val)) || (columns[c] & (1<<val)) || (squares[(r/3)*3 + (c/3)] & (1<<val))){
                        return false;
                    } 

                    rows[r] |= (1<<val);
                    columns[c] |= (1<<val);
                    squares[(r/3)*3 + (c/3)] |= (1<<val);
                }
            }
        }

        return true;
    }
};
