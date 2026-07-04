class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = 0;
         int r = 0;
        for(int weight: weights){
            maxi = max(maxi, weight);
            r+=weight;
        }
        if(n<=days) return maxi;
        int l = maxi;
       
       while(l<=r){
        int mid = l+(r-l)/2;
        int count = 1;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=weights[i];
            if(curr>mid) {
                count++;
                curr=weights[i];
            }
        }
        // count++;
        if(count == days) return mid;
        else if(count>days) l = mid+1;
        else r=mid-1;
       }
       return l;
    }
};