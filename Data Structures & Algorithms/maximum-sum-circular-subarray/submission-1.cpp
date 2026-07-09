class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;

        int maxSum=nums[0];
        int currMax=nums[0];

        int minSum=nums[0];
        int currMin = nums[0];

        for(const int& num: nums){
            totalSum+=num;

            currMax = max(num, currMax+num);
            maxSum = max(currMax, maxSum);

            currMin = min(num, currMin+num);
            minSum = min(minSum, currMin);
        }
        if(currMax<0) return currMax;
        return max(currMax, totalSum-currMin);
    }
};