class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> nodes(n);
        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            nodes[i] = {};
        }
        for (vector<int>& edge : edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        queue<int> que;
        que.push(0);
        visited.insert(0);
        while (!que.empty()) {
            // N++;
            int temp = que.front();
            que.pop();
            // if(visited.count(temp)>0) return false;
            // visited.insert(temp);
            if(nodes[temp].empty()) return false;
            for(int i: nodes[temp]){
                if(visited.count(i)==0)que.push(i);
                visited.insert(i);
            }
        }
        return visited.size()==n ? true: false;
    }
};
