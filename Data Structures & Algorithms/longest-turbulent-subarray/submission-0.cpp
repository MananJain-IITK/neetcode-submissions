class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1) return 1;
        vector<int> diff(arr.size()-1,0);
        for(int i=0;i<arr.size()-1;i++){
            diff[i] = arr[i]-arr[i+1];
        }
        
        int curr=1;
        int ans=1;

        for(int i=0;i<diff.size()-1;i++){
            if(diff[i]*diff[i+1]<0) {
                curr++;
                ans = max(ans, curr);
                }
            else{
                curr = 1;
            }
        }
        return ans+1;
    }
};