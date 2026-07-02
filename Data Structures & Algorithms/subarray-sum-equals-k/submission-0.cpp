class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int ans = 0;
        int sum =0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
           ans += prefix[sum-k];
           prefix[sum]++;
        }
        return ans;
    }
};