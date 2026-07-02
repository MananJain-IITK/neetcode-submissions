class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string curr = "";
        stack<string> words;
        stack<int> nums;
        int k=0;
        for(char c: s){
            if(c>='0'&&c<='9'){
                k=k*10+ (c-'0');
            }else if(c=='['){
                words.push(curr);
                nums.push(k);
                curr="";
                k=0;
            }else if(c==']'){
                string temp = curr;
                curr = words.top();
                words.pop();
                int count = nums.top();
                nums.pop();
                for(int i=0;i<count;i++) curr+=temp;
            }else curr +=c;
        }
        return curr;
    }
};