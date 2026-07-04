class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        // unordered_map<char, int> idxs;
        int res = 0;
        int n = s.size();
        int slow = 0;
        if(n==0) return 0;
        for(int i=0; i<n; i++){
            char temp = s[i];
            if(freq[temp] == 0){
                res = max(res, i-slow+1);
            }else{
                slow = i;
                freq[temp]--;
            }
            // idxs[temp] = i;
            freq[temp]++;
        }
        return res;
    }
};
