class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target) {
                if (nums[l] > target)
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if(nums[r]>target) l =mid+1;
                else r = mid -1;
            }
        }
        return false;
    }
};