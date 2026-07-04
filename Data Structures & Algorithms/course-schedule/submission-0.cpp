class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courses(numCourses, -1);
        for(auto prereq: prerequisites){
            courses[prereq[0]] = prereq[1];
        }
        for(int i: courses){
            if(i==-1) return true;
        }
        return false;
    }
};
