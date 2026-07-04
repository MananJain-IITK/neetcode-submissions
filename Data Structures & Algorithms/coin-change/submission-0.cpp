class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return max(-1, dfs(memo, coins, amount, 0));
    }

   private:
    int dfs(unordered_map<int, int>& memo, vector<int>& coins, int amt, int i) {
        if (amt == 0) return 0;
        if (memo.find(amt) != memo.end()) return memo[amt];
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amt - coins[i] >= 0) {
                res = min(res, 1 + dfs(memo, coins, amt-coins[i], i));
            }
        }
        memo[amt] = res;
        return res;
    }
};
