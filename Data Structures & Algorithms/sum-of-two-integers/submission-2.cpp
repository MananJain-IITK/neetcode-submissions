class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b;
        unsigned int carry = a&b;
        while(carry!=0){
            sum^=carry<<1;
            carry &= sum;
        }
        return sum;
    }
};
