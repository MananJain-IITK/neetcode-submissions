class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n=nums.size();
        for(int l=0; l<nums.size()-1; l++){
            int r=l+1;
            while(r<nums.size() && nums[l]==nums[r]){
                r++;
            }
            if(r!=l+1){
                nums.erase(nums.begin()+l, nums.begin()+r-1);
            }
        }
        return nums.size();
    }
};