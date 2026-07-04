class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        unordered_map<int, int> hash;
        int ans=0;
        int n=people.size();
        for(int i=0; i<n; i++){
            hash[limit-people[i]]++;
            // people[i] = limit-people[i];
        }
        for(int i=0;i<n;i++){
            if(people[i]==0 )ans++;
            else if(hash[people[i]]>0){
                ans++;
                hash[people[i]]--;
            }
        }
        return ans;
    }
};