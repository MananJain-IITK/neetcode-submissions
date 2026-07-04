class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()-1;
        int mid = 0;
        while(l<=r){
            mid = l + (r-l)/2;
            int num = matrix[mid][0];
            if(num== target) return true;
            else if(num>target) r = mid - 1;
            // else l = mid+1;
        }
        l = 0; r = matrix[mid].size()-1;
        int mid1 = mid;
        while(l<=r){
            mid = l + (l-r)/2;
            int num = matrix[mid1][mid];
            if(num==target) return true;
            else if(num>target) r = mid - 1;
            else l =mid + 1;
        }
        return false;
    }
};
