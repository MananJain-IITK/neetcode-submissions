class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> prereq(numCourses,-1);
        for(vector<int> course: prerequisites){
            prereq[course[1]] = course[0];
        }
        vector<bool> ans(queries.size(), true);
        int i=0;
        for(vector<int> query: queries){
            int curr = query[1];
            while(curr!=query[0]){
                if(curr==-1){
                    ans[i] = false;
                    break;
                }
                curr = prereq[curr];
            }
            i++;
        }
        return ans;
    }
};