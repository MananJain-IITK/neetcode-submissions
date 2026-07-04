class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n) int k = n % k;
        if (k == 0) return;

        // int l=k-1, r=n-1;

        // while(l!=-1){
        //     swap(nums[l], nums[r]);
        //     l--;
        //     r--;
        // }
        for(int i=0;i<k;i++) nums.push_back(nums[i]);
        nums.erase(nums.begin(), nums.begin()+k);
    }
};