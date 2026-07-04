class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> isSeen;
        while(n!=1){
            if(isSeen[n]) return false;
            int temp=0;
            while(n!=0){
                temp += pow(n%10.0,2.0);
                n/=10;
            }
            n=temp;
            isSeen[n] = true;
        }
        return true;
    }
};
