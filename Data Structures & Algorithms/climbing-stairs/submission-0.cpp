class Solution {
public:
    int climbStairs(int n) {
        int oneStep = 1;
        int twoStep = 2;
        if(n==1) return oneStep;
        if(n==2) return twoStep;
        int ans = 0;
        for(int i=3; i<=n; i++){
            ans += oneStep + twoStep;
            oneStep = twoStep;
            twoStep = ans;
        }
        return ans;
    }
};
