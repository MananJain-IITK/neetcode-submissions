class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n+1,-1); 
        return  dp(n, memo);
    }
private:
    int dp(int n, vector<int>& memo){
        if(n==1) return 1;
        // if(n==1) return 1;
        // if(n==2) return 1;
        if(memo[n]!=-1) return memo[n];
        int curr = 0;
        for(int i=1;i<=n-1;i++){
            curr = max(i* max(n-i, dp(n-i,memo)), curr);
        }
        return memo[n] = curr;
        // return curr;
    }
};