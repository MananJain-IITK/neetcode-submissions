class Solution {
   public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        double ans = 1;
        long power = abs(long(n));
        while (power) {
            if(power&1) ans *= x;
            x *= x;
            n /= 2;
        }
        if (n>0) {
            // if (n % 2 != 0) return x * y;
            return ans;
        }

         if (n<0) {
            // if (n % 2 != 0) return 1/(x * y);
            return 1/(ans);
        }
    }
};
