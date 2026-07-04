class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> stk.push("/");
        string ans = ""; 
        for(int i=0;i<n; i++){
            string word = "";
            while(i<n&&path[i]!='/'){
                word.push_back(path[i]);
                i++;
            }
            if(!word.empty() && word!="."){
                if(word==".."&&stk.top()!="/") stk.pop();
                else stk.push(word);
            }
        }
        while(stk.size()>1){
            ans += "/" + stk.top();
            stk.pop();
        }
        if(stk.size()>1) return "/";
        return ans;
    }
};