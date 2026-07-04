class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;
        else if(n1==0) return true;

        unordered_map<char, int> freq;
        for(int i=0; i<n1; i++){
            freq[s1[i]]++;
        }

        for(int i=0; i<n2-n1; i++){
            unordered_map<char, int> copyFreq = freq;
            int j=i;
            while(j!=i+2){
                copyFreq[s2[i]]--;
            }
            if(copyFreq.empty()){
                return true;
            }else{
                return false;
            }
        }
    }
};
