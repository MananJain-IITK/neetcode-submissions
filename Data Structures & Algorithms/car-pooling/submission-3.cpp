class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> line(1001,0);
        for(const auto& trip: trips){
            line[trip[1]] += trip[0];
            line[trip[2]] -= trip[0];
        }
        int count=0;
        for(int i: line){
            count+=i;
            if(count>capacity) return false;
        }
        return true;
    }
};