class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        // for (int i = 0; i < n; i++) {
            while (!minHeap.empty()) {
                auto [currCost, currNode] = minHeap.top();
                minHeap.pop();

                if(currCost>dist[currNode]) continue;
                // if(currNode == i) {
                //     ans+= currCost;
                //     continue;
                // }
                for(auto& neigh: adj[currNode]){
                    int nextNode = neigh.first;
                    int weight = neigh.second;
                    int newCost = currCost + weight;

                    if(newCost<dist[nextNode]){
                        dist[nextNode] = newCost;
                        minHeap.push({newCost, nextNode});
                    }
                }
            }
        // }
        // int ans = 0;
        for(int i=1; i<n+1; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
