class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = max(piles.begin(), piles.end());
        if(h<=n) return maxPile;
        return 0;
    }
};
