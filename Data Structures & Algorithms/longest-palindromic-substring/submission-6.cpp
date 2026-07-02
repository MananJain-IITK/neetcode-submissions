class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0, res=0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(res<(j-i+1)){
                        resIdx = i;
                        res = j-i+1;
                    }
                }
            }
        }
        return s.substr(resIdx, res);
    }
};
