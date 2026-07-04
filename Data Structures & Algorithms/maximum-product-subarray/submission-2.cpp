class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int globalMax = nums[0];

        for(int i=1; i<nums.size(); i++){
            int curr = nums[i];
            if(curr<0){
                swap(minSoFar, maxSoFar);
            }
            minSoFar = min(curr, curr*minSoFar);
            maxSoFar = max(curr, curr*maxSoFar);
            globalMax = max(maxSoFar, maxSoFar);
        }
        return globalMax;
    }
};
