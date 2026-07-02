class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> premap(numCourses);
        for(int i=0; i<numCourses; i++){
            premap[i] = {};
        }
        unordered_set<int> path;
        for(auto prereq: prerequisites){
            premap[prereq[0]].push_back(prereq[1]);
        }
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, premap, path)) return false;
        }
        return true;
    }

private:
    bool dfs(int crs, vector<vector<int>>& premap, unordered_set<int>& path){
        if(path.count(crs)>0) return false;
        if(premap[crs].empty()) return true;
        path.insert(crs);
        for(int i: premap[crs]){
            if(!dfs(i, premap, path)) return false;
        }
        path.erase(crs);
        premap[crs].clear();
        return true;
    }
};
