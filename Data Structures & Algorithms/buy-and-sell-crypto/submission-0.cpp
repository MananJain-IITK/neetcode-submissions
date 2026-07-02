class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int l=0;
        int r=0;
        int minBuy = prices[0];
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, prices[i] - minBuy);
            minBuy = min(prices[i], minBuy);
        }

        return maxProfit;
    }
};
