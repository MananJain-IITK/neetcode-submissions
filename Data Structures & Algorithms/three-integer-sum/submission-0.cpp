// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             int target1 = 0 - nums[i];
//             for(int j=i+1; j<n; j++){
//                 int target2 = target1 - nums[j];
//                 if(nums[n-j] == target2){
//                     ans.push_back({nums[i], nums[j], nums[n-j-1]});
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // unordered_set<vector<int>> ans_set;
        sort(nums.begin(), nums.end());
        // if(nums[0] > 0) return ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target1 = 0 - nums[i];
            int l = i+1;
            int r = n -1;
            while(l<r){
                if(nums[l]+nums[r] > target1) r--;
                else if(nums[l]+nums[r] < target1) l++;
                else if(nums[l]+nums[r] == target1){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    l++;
                    while(l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }

        // vector<vector<int>> ans(ans_set.begin(), ans_set.end());

        return ans;
    }
};

