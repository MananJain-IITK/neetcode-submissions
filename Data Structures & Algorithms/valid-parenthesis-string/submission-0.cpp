class Solution {
   public:
    bool checkValidString(string s) {
        int n = s.size();
        int maxOpen = 0, minOpen = 0;
        for(char c: s){
            if(c=='('){
                maxOpen++;
                minOpen++;
            }else if(c==')'){
                maxOpen--;
                minOpen--;
            }else{
                maxOpen++;
                minOpen--;
            }

            if(maxOpen<0) return false;
            minOpen = max(0, minOpen);
        }
        return minOpen==0;
    }
};
