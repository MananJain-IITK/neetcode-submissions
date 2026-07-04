class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        unordered_map<int, int> hash;
        int ans=0;
        int n=people.size();
        for(int i=0; i<n; i++){
            hash[people[i]] = i;
            // people[i] = limit-people[i];
        }
        for(int i=0;i<n;i++){
            if(people[i]==-1) continue;
            int diff = limit - people[i];
            if(hash[diff]>=0){
                ans++;
                people[hash[diff]] = -1;
                people[i] = -1;
            }
            else {
                hash[people[i]] = -1;
                ans++;
            }
        }
        return ans;
    }
};