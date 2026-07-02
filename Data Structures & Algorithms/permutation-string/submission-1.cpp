class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // bool ans = false;
       int n1 = s1.size();
       int n2 = s2.size();
       if(n1>n2) return false;
       else if(n1==0) return true;
        vector<int> freq(26);

        for(char c: s1){
            freq[c-97]++;
        }
        for(int i=0; i<=n2-n1; i++){
            vector<int> wind_freq(26);
            for(int j=i; j<i+n1; j++){
                wind_freq[s2[j]-97]++;
            }
            if(wind_freq==freq) return true;
        }
        return false;
    }
};
