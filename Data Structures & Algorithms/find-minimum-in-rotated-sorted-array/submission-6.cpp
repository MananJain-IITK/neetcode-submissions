class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1;
        int mid = 0;
        while(l<r){
            mid = l + (r-l)/2;
            int num = nums[mid];
            if(num>nums[r]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return nums[l];
    }
};
