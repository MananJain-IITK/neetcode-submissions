class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return dfs(s, words,memo, 0);
    }

private:
    bool dfs(string& s, unordered_set<string>& words, vector<int>& memo, int l){
        if(l==s.size()) return true;
        if(memo[l]!=-1) return memo[l];
        int r=l;
        while(r<s.size()){
            if(words.count(s.substr(l, r-l+1))>0)  if(dfs(s, words, memo, r+1)) {
                memo[l] = 1;
                return true;
                }
            r++;
        }
        memo[l] = 0;
        return false;
    }
};
