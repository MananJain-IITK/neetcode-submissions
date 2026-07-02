class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbours(n);
        for(int i=0; i<n; i++){
            neighbours[i] = {};
        }
        for(vector<int> edge: edges){
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }

        queue<int> que;
        unordered_set<int> visited;
        int ans=0;
        for(int i=0; i<n; i++){
            if(visited.count(i)>0) continue;
            ans++;
            que.push(i);
            while(!que.empty()){
                int temp = que.front();
                visited.insert(temp);
                que.pop();
                for(int x: neighbours[temp]){
                    if(visited.count(x)==0)que.push(x);
                }
            }
        }
        return ans;
    }
};
