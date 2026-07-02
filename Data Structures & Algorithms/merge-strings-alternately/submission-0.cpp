class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size();
        int n2 = word2.size();

        // if(n2>n1){
        //     swap(word1, word2);
        //     swap(n1, n2);
        // }
        int mini = min(n1, n2);
        for(int i=0; i<mini; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if(n1>n2) ans += word1.substr(n2);
        if(n2>n1) ans += word2.substr(n1);

        return ans;
    }
};