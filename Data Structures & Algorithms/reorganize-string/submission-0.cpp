class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char c: s){
            freq[c-'a']++;
            if(freq[c-'a']>(s.size()/2)) return "";
        }
        priority_queue<pair<int,char>> maxHeap;
        for(int i=0;i<26;i++){
            if(freq[i]!=0) maxHeap.push({freq[i],'a'+i});
        }
        string ans;
        pair<int,char> prev = maxHeap.top();
        ans+=prev.second;
        maxHeap.pop();
        while(!maxHeap.empty()){
            pair<int,char> temp = maxHeap.top();
            maxHeap.pop();
            ans+=temp.second;
            if(--(prev.first)) maxHeap.push(prev);
            prev=temp;
        }
        return ans;
    }
};