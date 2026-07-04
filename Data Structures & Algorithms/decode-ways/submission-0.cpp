class Solution {
public:
    int numDecodings(string s) {
        int ans=0;
        dfs(ans, s, 0);
        return ans;
    }

private:
    void dfs(int& ans, string& s, int i){
        if(i>=s.size()){
            ans++;
            return;
        }
        if(stoi(s.substr(i, 1))>=1 && stoi(s.substr(i,1))<=9){
            dfs(ans, s, i+1);
        }
        if(stoi(s.substr(i, 2))>=10 && stoi(s.substr(i,2))<=26){
            dfs(ans, s, i+2);
        }
    }
};
