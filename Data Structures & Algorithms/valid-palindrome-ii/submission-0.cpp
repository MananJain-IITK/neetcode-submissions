class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        bool isDeleted = false;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else if(isDeleted) return false;
            else{
                isDeleted = true;
                if(s[r-1]==s[l]) r--;
                else l++;
            }
        }
        return true;
    }
};