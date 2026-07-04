class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans = nums[n-1];
        int curr = nums[n-1];
        for(int i=n-2; i>=0; i--){
            curr += nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};
