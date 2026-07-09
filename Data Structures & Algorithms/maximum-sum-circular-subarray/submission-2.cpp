class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;

        int maxSum=nums[0];
        int currMax=0;

        int minSum=nums[0];
        int currMin = 0;

        for(const int& num: nums){
            totalSum+=num;

            currMax = max(num, currMax+num);
            maxSum = max(currMax, maxSum);

            currMin = min(num, currMin+num);
            minSum = min(minSum, currMin);
        }
        if(maxSum<0) return currMax;
        return max(maxSum, totalSum-minSum);
    }
};