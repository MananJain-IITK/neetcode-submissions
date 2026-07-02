class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses,false));
        for(const vector<int>& prereq: prerequisites) isPrereq[prereq[0]][prereq[1]] = true;
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    isPrereq[i][j] = isPrereq[i][j] || (isPrereq[i][k] && isPrereq[k][j]);
                }
            }
        }
        vector<bool> ans;
        ans.reserve(numCourses);
        for(const vector<int>& query: queries){
            ans.push_back(isPrereq[query[0]][query[1]]);
        }
        return ans;
    }
};