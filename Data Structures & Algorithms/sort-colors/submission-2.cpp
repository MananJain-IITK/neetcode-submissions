class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int freq[3] = {0};

        for (int num : nums) {
            freq[num]++;
        }
        int i = 0;

        while (i<n && freq[0] != 0) {
            freq[0]--;
            nums[i] = 0;
            i++;
        }
        while (i<n && freq[1] != 0) {
            freq[1]--;
            nums[i] = 1;
            i++;
        }
        while (i<n && freq[2] != 0) {
            freq[2]--;
            nums[i] = 2;
            i++;
        }
    }
};