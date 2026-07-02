class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> sl(n+1,0);
        // unordered_set<int> judges;
        for(vector<int> people: trust){
            // judges.insert(people[1]);
            sl[people[1]]++;
        }
        for(vector<int> people: trust){
            sl[people[0]]=0;
        }
        for(int i=0;i<n+1;i++) if(sl[i]==n-1) return i;
        return -1;
    }
};