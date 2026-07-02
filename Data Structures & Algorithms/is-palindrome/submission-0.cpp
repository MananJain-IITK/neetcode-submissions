class Solution {
public:
    bool isPalindrome(string s) {
        string new_s = "";
        for(char c: s){
            if(isAlphaNumeric(c)) new_s.push_back(tolower(c));
        }
        int n = new_s.size();
        for(int i=0; i<n; i++){
            if(new_s[i] != new_s[n-1-i]) return false;
        }
        return true;
    }

    bool isAlphaNumeric(char c){
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) return true;

        return false;
    }
};
