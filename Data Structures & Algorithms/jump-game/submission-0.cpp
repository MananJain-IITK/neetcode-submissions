class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0) return false;
        int n = nums.size();
        int i=0;
        while (i<n){
            int j=i+nums[i];
            if(j>=n-1) return true;
            while(nums[j]==0 && j>i) j--;
            if(i==j) return false;
            i=j;
        }
        return true;
    }
};
