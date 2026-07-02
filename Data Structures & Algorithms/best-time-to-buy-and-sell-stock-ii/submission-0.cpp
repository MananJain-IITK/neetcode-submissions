class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int n= prices.size();
        vector<vector<int>> cache(n,vector<int>(2,-1));
        return dfs(prices, cache, 0, 0);
    }

private:
    int dfs(vector<int>& prices, vector<vector<int>>& cache, int i, int holding){
        if(i>=prices.size()) return 0;
        if(cache[i][holding]!=-1) return cache[i][holding];
        int profit=0;
        if(holding == 0){
            profit = max(dfs(prices, cache, i+1,0), -prices[i]+dfs(prices, cache, i+1, 1));
        }else{
            profit = max(prices[i]+dfs(prices, cache, i+1,0), dfs(prices, cache, i+1, 1));
        }
        return cache[i][holding]=profit;
    } 
};