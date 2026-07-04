class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid = l + (r-l)/2;
        while(l<=r ){
            int num = nums[mid];
            if(num==target) return mid;
            else if(num>target) r = mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
