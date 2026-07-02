class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i]==s[j] && (j-i<3 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
