class UnionFind{
private:
    vector<int> rank;
    vector<int> parent;

public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) return false;

        if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
            rank[rootX] += rootY;
        }else{
            parent[rootX] = rootY;
            rank[rootY] += rootX;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size()+1);
        for(auto& edge: edges){
            if(!uf.unionSet(edge[0], edge[1])){
                return {edge[0], edge[1]};
            }
        }
        return {};
    }
};
