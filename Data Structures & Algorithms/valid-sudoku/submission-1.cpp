class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Fast I/O trick
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int rows[9] = {0}, cols[9] = {0}, squares[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1';
                int mask = 1 << val;
                int s_idx = (r / 3) * 3 + (c / 3);

                // Combined check: is this bit set in ANY of the three?
                if ((rows[r] & mask) || (cols[c] & mask) || (squares[s_idx] & mask)) {
                    return false;
                }

                // Update all three
                rows[r] |= mask;
                cols[c] |= mask;
                squares[s_idx] |= mask;
            }
        }
        return true;
    }
};