class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        // int l=0,r=n-1;
        bool isDeleted = false;
       
        return dfs(s, 0, n-1, isDeleted);
    }

private:
    bool dfs(string& s, int l, int r, bool isDeleted){
        if(isDeleted && s[l]!=s[r]) return false;

        while(l<=r){
            if(s[l]!=s[r]){
                isDeleted = true;
                 return dfs(s,l+1,r,isDeleted) || dfs(s,l,r-1,isDeleted) ;
            }
            l++;
            r--;
        }
        return true;
    }
};