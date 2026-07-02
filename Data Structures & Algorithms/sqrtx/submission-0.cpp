class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int r=x;
        while(l<=r){
            int mid = l +(r-l)/2;
            int target = x/mid;
            if(mid==target) return mid;
            else if(mid>target) r= mid-1;
            else l=mid+1;
        }
        return r;
    }
};