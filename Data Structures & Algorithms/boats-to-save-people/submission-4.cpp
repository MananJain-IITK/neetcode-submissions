class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int m = *max_element(people.begin(), people.end());
        vector<int> count(m+1,0);
        for(int p:people) count[p]++;
        int idx=0, i=0;
        while(idx<people.size()){
            while(count[i]==0) i++;
            people[idx++] = i;
            count[i]--;
        }
        int l=0, ans =0, r=people.size()-1;
        while(l<=r){
            int remain = limit-people[r--];
            ans++;
            if(l<=r && remain>=people[l]) l++;
        }
        return ans;
    }
};