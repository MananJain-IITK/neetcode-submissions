class StockSpanner {
public:
    vector<int> span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        span.push_back(price);
        int n=span.size()-1;
        int ans=0;
        while(n>=0&&price>=span[n]) {
            ans++;
            n--;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */