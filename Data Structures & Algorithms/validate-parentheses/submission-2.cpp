class Solution {
public:
    bool isValid(string s) {
        stack<char> tracker;
        int n = s.size();
        if(n==0 ) return true;
        else if(n==1) return false;
        tracker.push(s[n-1]);
        for(int i=n-2; i>=0; i--){
            if((!tracker.empty())&&(s[i] - tracker.top()<=2)&&(s[i] - tracker.top()<=2)){
                tracker.pop();
                // continue;
            }else{
            tracker.push(s[i]);
            }

        }

        if(tracker.empty()){
            return true;
        }else{
            return false;
        }
    }
};
