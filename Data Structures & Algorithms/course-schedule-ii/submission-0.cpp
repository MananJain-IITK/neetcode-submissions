class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        unordered_set<int> visited;
        unordered_set<int> done;
        vector<int> ans(numCourses);

        for (vector<int> pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preMap, visited, done, ans)) return {};
        }
        return ans;
    }

   private:
    bool dfs(int crs, vector<vector<int>>& preMap, unordered_set<int>& visited,
             unordered_set<int>& done, vector<int>& ans) {
        if (visited.count(crs) > 0) return false;
        if (preMap[crs].empty()) {
            if (done.count(crs) == 0) ans.push_back(crs);
            done.insert(crs);
            return true;
        }

        visited.insert(crs);
        for (int i : preMap[crs]) {
            if (!dfs(i, preMap, visited, done, ans)) return false;
        }
        visited.erase(crs);
        preMap[crs].clear();
        if (done.count(crs) == 0) ans.push_back(crs);
        done.insert(crs);
        return true;
    }
};
