class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        for(int i=0; i<n; i++){
            int y = target - numbers[i];
            for(int j=i+1; j<n; j++){
                if(numbers[j] == y){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                }
            }
        }

        return ans;
    }
};
