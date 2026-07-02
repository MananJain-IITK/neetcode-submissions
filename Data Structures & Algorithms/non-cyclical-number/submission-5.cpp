class Solution {
public:
    bool isHappy(int n) {
        n = double(n);
        unordered_map<double, bool> isSeen;
        while(n!=1){
            isSeen[n] = true;
            double temp=0;
            while(n!=0){
                temp += pow(n%10,2.0);
                n/=10.0;
            }
            n=temp;
            if(isSeen[n]) return false;
        }
        return true;
    }
};
