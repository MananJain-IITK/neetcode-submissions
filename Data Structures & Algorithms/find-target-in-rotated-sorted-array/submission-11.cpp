class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Scenario A: The LEFT half is perfectly sorted
            if (nums[l] <= nums[mid]) {
                // Is the target mathematically inside this perfectly sorted left half?
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1; // Yes, search left
                } else {
                    l = mid + 1; // No, it must be on the right
                }
            } 
            // Scenario B: The RIGHT half is perfectly sorted
            else {
                // Is the target mathematically inside this perfectly sorted right half?
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1; // Yes, search right
                } else {
                    r = mid - 1; // No, it must be on the left
                }
            }
        }
        
        return -1; // Safely outside the loop
    }
};