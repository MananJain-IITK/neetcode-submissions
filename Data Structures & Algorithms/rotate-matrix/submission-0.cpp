class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return;
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            vector<int> temp = matrix[l];
            matrix[l] = matrix[r];
            matrix[r] = temp;
            l++;
            r--;
        }
        int x = 0;
        while (x != n - 1) {
            int c = x + 1, r = x + 1;
            while (c < n && r < n) {
                int temp = matrix[x][c];
                matrix[x][c] = matrix[r][x];
                matrix[r][x] = temp;
                c++;
                r++;
            }
            x++;
        }
    }
};
