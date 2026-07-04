class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            int num = nums[mid];
            if(num==target) return mid;
            else if(num>nums[r]){
                if(target<nums[r]){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }else{
                if(target<nums[r]){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};
