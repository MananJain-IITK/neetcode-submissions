class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n==0) return 0;
        vector<int> freq(n); 
        int p = 0;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                freq[p]++;
            }else{
                p++;
                freq[p]++;
            }
        }
        int max = *max_element(freq.begin(), freq.end());
        return min(n, max+k);
    }
};
