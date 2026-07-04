class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int x=0, y=0;
        bool ans = true;
        backtrack(ans, board, word, x, y, 0);
        return ans;
    }
private:
    void backtrack(bool ans, vector<vector<char>>& board, string word, int x, int y, int idx){
        if(idx == word.size()){
            // ans = true;
            return;
        }
        for(int cy=y; cy<board.size();cy++){
            for(int cx=x; cx<board[0].size(); cx++){
                if(board[y][x] == word[idx]){
                    backtrack(ans,board, word, cx+1, cy, idx+1);
                    backtrack(ans,board, word, cx-1, cy, idx+1);
                    backtrack(ans,board, word, cx, cy+1, idx+1);
                    backtrack(ans,board, word, cx, cy-1, idx+1);
                }
                else{
                    ans = false;
                    // continue;
                }
            }
        }
    }
};
