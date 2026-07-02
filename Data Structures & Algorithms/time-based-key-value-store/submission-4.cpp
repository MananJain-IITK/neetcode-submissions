class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
        
    }
    
    string get(string key, int timestamp) {
        
        
        if(!store.contains(key)) return "";
        int n = store[key].size();
        // if(n==1) return store[key][0].first;
        int l=0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int value = store[key][mid].second;
            if(value==timestamp)return store[key][mid].first;
            else if(value<timestamp){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if(r>=0){
            return store[key][r].first;
        }else{
            return "";
        }
    }
};
