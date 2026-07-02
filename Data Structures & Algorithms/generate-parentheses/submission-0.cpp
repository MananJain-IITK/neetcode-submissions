class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // vector<int> freq(2, n);
        int closedN = 0, openN = 0;
        vector<string> ans;
        string currPath;
        backtrack(ans, currPath, closedN, openN, n);
        return ans;
    }

private:
void backtrack(vector<string>& ans, string& currPath, int closedN, int openN, int n){
    if(currPath.size() == 2*n){
        ans.push_back(currPath);
        return;
    }
    if(openN<n){
        currPath.push_back('(');
        backtrack(ans, currPath, closedN, openN+1,n);
        currPath.pop_back();
    }
    if(closedN<openN){
        currPath.push_back(')');
        backtrack(ans, currPath, closedN+1, openN,n);
        currPath.pop_back();
    }
}
};
