class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n+1,-1); 
        return dp(n, memo);
    }
private:
    int dp(int n, vector<int>& memo){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(memo[n]!=-1) return memo[n];
        int curr = n;
        for(int i=1;i<=n;i++){
            curr = max(curr, i*dp(n-i,memo));
        }
        return memo[n] = curr;
    }
};