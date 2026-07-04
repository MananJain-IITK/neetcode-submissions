class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        nums1.erase(nums1.begin()+m, nums1.end());
            while(j<n && i<m){
                if(nums1[i]<nums2[j]){
                    i++;
                }else{
                    nums1.insert(nums1.begin()+i,nums2[j]);
                    j++;
                    // i++;
                }
            }
            while(j<n){
                nums1.push_back(nums2[j]);
                j++;
            }
        
    }
};