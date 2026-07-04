class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        map<pair<int, int>, bool> checker;
        int ans=0;
        int x=0;
        int n=s.size();
        for(int l=0;l<n; l++){
            for(int r=0; r<n; r++){
                if(!checker.contains({l,r})){
                    checker[{l,r}] = isPalindrome(s, l, r);
                }
                if(checker[{l,r}]) ans = max(ans, r-l+1);
                if(ans==r-l+1) x = l;
            }
        }
return s.substr(x-1, ans);
    }

private:
    bool isPalindrome(string& word, int l, int r){
        while(l<=r){
            if(word[l]!=word[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
