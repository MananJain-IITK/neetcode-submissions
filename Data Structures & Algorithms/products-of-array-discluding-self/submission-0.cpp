class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int max_product = 1;
        bool isZero = false;
        bool isMultiZero = false;
        int n  = nums.size();
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(num != 0){
                max_product *= num;
            }else{
                if(!isZero){
                    isZero = true;
                }else if( isZero and !isMultiZero){
                    isMultiZero = true;
                }
            }
        }
        vector<int> ans;
        for (auto num: nums){
            if(isMultiZero){
                ans.push_back(0);
            }
            else if(isZero){
                if(num != 0){
                    ans.push_back(0);
                }else{
                    ans.push_back(max_product);
                }
            }else{
                ans.push_back(max_product/num);
            }
        }

        return ans;
    }
};
