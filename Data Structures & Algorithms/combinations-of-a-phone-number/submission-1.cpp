class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string currPath;
        backtrack(digits, ans, currPath, dict, 0);
        return ans;
    } 

private:
    void backtrack(string& digits, vector<string>& ans, string& currPath, vector<string>& dict, int idx){
        if(currPath.size() == digits.size()){
            ans.push_back(currPath);
            return;
        }

        // for(int i= idx; i<digits.size(); i++){
            string temp = dict[stoi(digits.substr(idx,1))];
            for(int j=0; j<temp.size(); j++){
                currPath.push_back(temp[j]);
                backtrack(digits, ans, currPath, dict, idx+1);
                currPath.pop_back();
            // }
        }
    }
};
