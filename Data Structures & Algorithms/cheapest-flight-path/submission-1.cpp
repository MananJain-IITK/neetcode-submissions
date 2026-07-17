class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj;
        adj.resize(n);
        for (auto const& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> cost(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int price = pq.top().first;
            int next = pq.top().second;
            pq.pop();

            if (price > cost[next]) continue;

            if (k >= 0) {
                for (const pair<int, int>& i : adj[next]) {
                    if (i.second + price < cost[i.first]) {
                        cost[i.first] = i.second + price;
                        pq.push({i.second, i.first});
                    }
                }
                k--;
            }
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
