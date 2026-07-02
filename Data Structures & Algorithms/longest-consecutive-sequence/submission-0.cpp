class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(), nums.end());
        int ans = 0;
        for(auto num : store){
            if(store.find(num-1) == store.end()){
                int length = 1;
                while(store.find(num+length) != store.end()){
                    length++;
                }
                ans = max(length, ans);
            }
        }
        return ans;
    }
};
