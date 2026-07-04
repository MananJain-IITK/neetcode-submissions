// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         if(n==0) return 0;
//         vector<int> freq(n);
//         freq[0] = 1;
//         int p = 0;
//         for(int i=1; i<n; i++){
//             if(s[i] == s[i-1]){
//                 freq[p]++;
//             }else{
//                 freq[++p]++;
//             }
//         }
//         int max = *max_element(freq.begin(), freq.end());
//         return min(n, max+k);
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n==0) return 0;
        int ans,l = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for(char c: charSet){
            int count = 0;;
            for(int r=0; r<n; r++){
                if(s[r] == c){
                    count++;
                }

                while(r-l+1 - count>k){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                ans = max(ans, r-l+1);
            }
        }
        
        return ans;
    }
};
