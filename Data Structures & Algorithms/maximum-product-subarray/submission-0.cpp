class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int temp=1;
            for(int j=i; j<nums.size(); j++){
                temp = temp*nums[j];
                ans = max(ans, temp);
            }
            
        }
        return ans;
    }
};
