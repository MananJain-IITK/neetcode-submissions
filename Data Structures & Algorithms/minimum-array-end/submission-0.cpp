class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> ans(n,x);
        for(int i=1;i<n;i++){
            ans[i] +=pow(2,i);
        }
        return ans[n-1];
    }
};