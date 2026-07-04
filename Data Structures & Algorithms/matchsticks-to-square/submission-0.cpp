class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        int sum=0;
        for(int matchstick: matchsticks) sum+=matchstick;
        if(sum%4!=0) return false;
        sort(matchsticks.begin(),matchsticks.end());
        int side = sum/4;
        int l=0, r=matchsticks.size()-1;
        while(l<=r){
            int limit = side - matchsticks[r];
            
            while(0<limit){
                limit -= matchsticks[l];
                l++;
            }
            if(limit==0) r--;
            if(limit<0) return false;
        }
        return true;
    }
};