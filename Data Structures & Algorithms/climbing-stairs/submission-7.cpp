class Solution {
public:
    int climbStairs(int n) {
        int oneStep = 1;
        int twoStep = 1;
        
        for(int i=0; i<n; i++){
            int temp = one;
            one += two;
            two = temp;
        }
        return one;
    }
};
