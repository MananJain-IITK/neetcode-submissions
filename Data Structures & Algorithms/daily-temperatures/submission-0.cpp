class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result;
        for(int i=0; i<n; i++){
            int j = i+1;
            while(j<n && temperatures[j]<temperatures[i]){
                j++;
            }
            
            if(j!=n) result.push_back(j-i);
            else result.push_back(0);
        }
        return result;
    }
};
