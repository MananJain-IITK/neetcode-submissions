class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int count=0;

        for(int i=0; i<nums.size(); i++){
            int temp = maxReach;
            maxReach = max(maxReach, nums[i]+i);
            if(maxReach!=temp) count++;
            if(maxReach>=nums.size()-1) return count;
        }
        return count;
    }
};
