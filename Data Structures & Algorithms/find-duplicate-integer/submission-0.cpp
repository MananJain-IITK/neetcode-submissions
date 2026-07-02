class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int num: nums){
            freq[num]++;
            if(freq[num] >1) return num;
        }
    }
};
