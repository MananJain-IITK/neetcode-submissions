class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> stk;
        stk.push_back("/");
        string ans = ""; 
        for(int i=0;i<n; i++){
            string word = "";
            while(i<n&&path[i]!='/'){
                word.push_back(path[i]);
                i++;
            }
            if(!word.empty() && word!="."){
                if(word==".."&&stk.back()!="/") stk.pop_back();
                else if(word=="..") continue;
                else stk.push_back(word);
            }
        }
        for(int i=1; i<stk.size();i++){
            ans += "/" + stk[i];
            // stk.pop_back();
        }
        if(ans.size()==0) return "/";
        return ans;
    }
};