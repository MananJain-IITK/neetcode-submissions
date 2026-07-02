class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeen[128] = {0}; 
        int res = 0;
        int slow = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char temp = s[i];
            slow = max(slow, lastSeen[temp]);

            res = max(res, i - slow + 1);
            lastSeen[temp] = i + 1;
        }
        return res;
    }
};