class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> prereq(numCourses);
        for (vector<int> course : prerequisites) {
            prereq[course[1]].push_back(course[0]);
        }
        vector<bool> ans(queries.size(), false);
        int i = 0;
        for (vector<int> query : queries) {
            queue<int> bfs;
            bfs.push(query[1]);
            while (!bfs.empty()) {
                int curr = bfs.front(); 
                if (curr == query[0]) {
                    ans[i] = true;
                    break;
                }
                for(int j=0; j<prereq[curr].size();j++)
                bfs.push(prereq[curr][j]);
                bfs.pop();
            }
            i++;
        }
        return ans;
    }
};