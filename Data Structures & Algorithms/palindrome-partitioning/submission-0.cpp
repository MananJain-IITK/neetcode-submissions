class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currPath;
        backtrack(s, ans, currPath, 0);
        return ans;
    }

   private:
    void backtrack(string& s, vector<vector<string>>& ans, vector<string>& currPath, int idx) {
        if(idx == s.size()){
            ans.push_back(currPath);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1)
            if (check(sub)) {
                currPath.push_back(sub);
                backtrack(s, ans, currPath, i + 1);
                currPath.pop_back();
            }
        }
    }

    bool check(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
