class Solution {
   public:
    int num;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> currPath(n, string(n, '.'));
        this->num = n;
        backtrack(ans, currPath, 0);
        return ans;
    }

   private:
    void backtrack(vector<vector<string>>& ans, vector<string>& currPath, int idx) {
        if (idx == num) {
            ans.push_back(currPath);
            return;
        }
        for (int i = 0; i < num; i++) {
            if (check(idx, i, currPath)) {
                currPath[idx][i] = 'Q';
                backtrack(ans, currPath, idx + 1);
                currPath[idx][i] = '.';
            }
        }
    }

    bool check(int r, int c, vector<string>& currPath) {
        for (int i = r - 1; i >= 0; i--) {
            if (currPath[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (currPath[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < num; i--, j++) {
            if (currPath[i][j] == 'Q') return false;
        }
        return true;
    }
};
