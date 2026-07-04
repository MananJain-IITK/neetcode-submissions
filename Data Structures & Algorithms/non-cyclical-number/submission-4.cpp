class Solution {
public:
    bool isHappy(int n) {
        n = double(n);
        unordered_map<double, bool> isSeen;
        while(n!=1){
            if(isSeen[n]) return false;
            double temp=0;
            while(n!=0){
                temp += pow(n%10,2.0);
                n/=10.0;
            }
            n=temp;
            isSeen[n] = true;
        }
        return true;
    }
};
