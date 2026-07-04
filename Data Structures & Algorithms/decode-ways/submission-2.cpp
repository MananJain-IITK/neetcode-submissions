class Solution {
   public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        int ans = dfs(s, memo, 0);
        return ans;
    }

   private:
    int dfs(string& s, vector<int>& memo, int i) {
        if (i >= s.size() - 1) {
            return 1;
        }
        if (s[i] == '0') return 0;
        if (memo[i] != -1) return memo[i];
        int ways = dfs(s, memo, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += dfs(s, memo, i + 2);
        }
        memo[i] = ways;
        return ways;
    }
};
