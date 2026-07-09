class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = 1;
        int n=nums.size();
        int ans = nums[l];
        int curr = nums[l];
        while(l!=r){
            if((curr+nums[r])<0){
                l=(r+1)%n;
                r=(r+1)%n;
                curr = nums[l];
            }else{
            curr=curr+nums[r];
            }
            r=(r+1)%n;
            ans = max(ans,curr);
        }
        return ans;
    }
};