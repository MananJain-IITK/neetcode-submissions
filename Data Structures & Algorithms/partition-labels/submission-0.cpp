class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]].first++;
            freq[s[i]].second = i;
        }
        vector<int> ans;
        int maxReach = 0;
        int i=0;
        while(i<s.size()){
            int count=0;
            while(i<=maxReach){
                freq[s[i]].first--;
                maxReach = max(maxReach,  freq[s[i]].second);
                i++;
                count++;
            }
            ans.push_back(count);
            maxReach = i;
        }
        return ans;
    }
};
