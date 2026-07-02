class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> isValid(n, true);
        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++){
                if(isValid[j]==true){
                    if(triplets[j][i]>target[i]) isValid[j] = false;
                }
            }
        }
        int max1=0, max2=0, max3=0;
        for(int i=0; i<n; i++){
            if(isValid[i]){
                max1 = max(triplets[i][0], max1);
                max2 = max(triplets[i][1], max2);
                max3 = max(triplets[i][2], max3);
            }
        }
        if(max1==target[0] && max2==target[1] && max3==target[2]) return true;
        return false;
    }
};
