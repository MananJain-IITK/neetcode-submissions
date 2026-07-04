class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1;
        int mid = 0;
        while(l<=r){
            mid = l + (r-l)/2;
            int num = nums[mid];
            if(num>l){
                l = mid + 1;
            }else if(num<r){
                r = mid - 1;
            }
        }
        int ans = 0;
        if(mid!=nums.size()-1) ans = nums[mid+1];
        else ans = nums[mid];
        return ans;
    }
};
