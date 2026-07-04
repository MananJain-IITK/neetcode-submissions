class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }

private:
    bool dfs(string& s, vector<string>& wordDict, int l){
        if(l==s.size()-1) return true;
        int r=l;
        while(l<s.size()){
            if(find(wordDict.begin(), wordDict.end(), s.substr(l, r-l+1))!=wordDict.end()) return dfs(s, wordDict, r+1);
            r++;
        }
        return true;
    }
};
