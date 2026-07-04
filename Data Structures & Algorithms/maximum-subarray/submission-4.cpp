class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans = nums[0];
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(sum<0){
                sum=0;
                ans = nums[i];
                continue;
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};
