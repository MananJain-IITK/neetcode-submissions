class Solution {
   public:
    int numSquares(int n) {
        unordered_map<int, int> memo;
        return dfs(n, memo);
    }

   private:
    int dfs(int n, unordered_map<int, int>& memo) {
        if(n==0) return 0;
        if(memo.find(n) != memo.end()) return memo[n];
        int curr = n;
        for(int i=1;i*i<=n;i++) curr = min(curr, 1+dfs(n-i*i,memo));
        return memo[n]=curr;
    }
};