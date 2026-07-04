class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int res = 1;
        int n = s.size();
        int slow = 0;
        if(n==0) return 0;
        for(int i=0; i<n; i++){
            char temp = s[i];
            if(freq[temp] == 0){
                res = max(res, i-slow);
            }else{
                slow=i;
                freq.clear();
            }
            freq[temp]++;
        }
        return res;
    }
};
