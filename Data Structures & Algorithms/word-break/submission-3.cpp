class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return dfs(s, wordDict,memo, 0);
    }

private:
    bool dfs(string& s, vector<string>& wordDict, vector<int>& memo, int l){
        if(l==s.size()) return true;
        if(memo[l]!=-1) return memo[l];
        int r=l;
        while(r<s.size()){
            if(find(wordDict.begin(), wordDict.end(), s.substr(l, r-l+1))!=wordDict.end())  if(dfs(s, wordDict, memo, r+1)) {
                memo[l] = 1;
                return true;
                }
            r++;
        }
        memo[l] = 0;
        return false;
    }
};
