#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 1. The Mathematical Cheat Code
        if (edges.size() != n - 1) return false;
        
        // 2. Build the Adjacency List (Cleaned up initialization)
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 3. BFS to check for fully connected graph
        queue<int> q;
        unordered_set<int> visited;
        
        // Setup the start state properly
        q.push(0);
        visited.insert(0); 
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // Explore all neighbors
            for (int neighbor : adj[curr]) {
                // Only push unvisited neighbors to prevent the "Bounce"
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        // 4. Did we reach every single node from Node 0?
        return visited.size() == n;
    }
};