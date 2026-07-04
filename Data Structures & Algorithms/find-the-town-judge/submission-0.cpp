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
            if(sl[people[0]]!=0) sl[people[0]]=0;
        }
        for(int i: sl) if(i!=0) return i;
        return -1;
    }
};