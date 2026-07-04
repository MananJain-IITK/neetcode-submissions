class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int count = 0;
        int time=0;
        // priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> minHeap;
        // for(const vector<int>& trip: trips){
        //     minHeap.push({{trip[1],trip[2]},trip[0]});
        // }
        // while(!minHeap.empty()){

        // }

        for(const vector<int>& trip: trips){
            int start = trip[1];
            int end = trip[2];
            if(time>start) count+=trip[0];
            else count = trip[0];
            if(count>capacity) return false;

            time=end;
        }
        return true;
    }
};