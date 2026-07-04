class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0]size();
        for(int r=0; r<ROWS; r++){
            if(board[r][0] == 'O') board[r][0] = '#';
            if(board[r][COLS-1] = 'O') board[r][COLS-1] = '#';
        }
        for(int c=0; r<COLS; r++){
            if(board[0][c] == 'O') board[0][c] = '#';
            if(board[ROW-1][c] = 'O') board[ROWS-1][c] = '#';
        }
        for(int r=0; r<ROWS; r++){
            for(int c=0; r<COLS; r++){

            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c,){
        if(board[r][c] == 'X' || board[r][c] == '#') return;
        board[r][c] = '#';
        dfs(board, r, c+1);
        dfs(board, r, c+1);
        v
    }
};
