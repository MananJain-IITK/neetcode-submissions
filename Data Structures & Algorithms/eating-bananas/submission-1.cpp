class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = piles[0];
        int minPile = piles[0];
        for(int pile: piles){
            maxPile = max(maxPile, pile);
            minPile = min(minPile, pile); 
        }
        if(h==n) return maxPile;
        int l=1, r=maxPile;
        while(l<=r){
            int hr= 0;
            int mid = l + (r-l)/2;
            for(int i: piles){
                hr+= ceil(i/mid);
            }
            if(hr==h) return mid;
            else if(hr>h) r = mid -1;
            else l = mid+1;

        }
    }
};
