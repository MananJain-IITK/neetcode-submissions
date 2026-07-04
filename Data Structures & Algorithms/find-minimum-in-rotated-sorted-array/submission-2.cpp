class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1;
        int mid = 0;
        while(l<=r){
            mid = l + (r-l)/2;
            int num = nums[mid];
            if(num>nums[l]&& num>nums[r]){
                l = mid + 1;
            }else if(num<nums[l] && num<nums[r]){
                r = mid - 1;
            }else if(num>nums[l] && num<nums[r]) return nums[0];
        }
        int ans = 0;
        if(mid!=nums.size()-1) ans = nums[mid+1];
        else ans = nums[mid];
        return ans;
    }
};
