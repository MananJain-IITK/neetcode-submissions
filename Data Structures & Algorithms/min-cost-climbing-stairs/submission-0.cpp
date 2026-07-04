class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> cache(n);
        // cache[0] = cost[0];
        // cache[1] = cost[1];
        int one = cost[0], two = cost[1];
        int ans = 0;
        for(int i=n-1; i>0;  i--){
            int temp = min(cost[i], cost[i-1]);
            if(temp == cost[i-1]) i--;
            ans+= temp;
        }
        return ans;
    }
};
