class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        bool ans = false;
        vector<pair<int, int>> seeds = seedFinder(board, word[0]);
        int count=0;
        while(count!= seeds.size()){
            ans = backtrack(board, word, seeds[count].first, seeds[count].second, 0);
            count++;
            if(ans) return ans;
        }
        
        return ans;
    }
private:
    bool backtrack(vector<vector<char>>& board, string word, int x, int y, int idx){
        if(idx==word.size()){
            // ans = true;
            return true;
        }
        if(x<0 || y<0 || y>=ROWS || x>=COLS || board[y][x] != word[idx] || path.count({x,y})) return false;

        path.insert({x,y});
        bool ans = backtrack(board, word, x+1, y, idx+1) || backtrack(board, word, x-1, y, idx+1) || backtrack(board, word, x, y+1, idx+1) ||backtrack(board, word, x, y-1, idx+1);
        path.erase({x,y});
        return ans;
    }

    vector<pair<int, int>> seedFinder(vector<vector<char>> board, char target){
        vector<pair<int, int>> seeds;
        for(int cy=0; cy<board.size();cy++){
            for(int cx=0; cx<board[0].size(); cx++){
                if(board[cy][cx] == target){
                   seeds.push_back({cx, cy});
                }
            }
        }
        return seeds;
    }
};
