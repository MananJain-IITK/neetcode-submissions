class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        if(a+b+c==0) return "";
        string ans;
        priority_queue<pair<int, char>> maxHeap;
        if (a) maxHeap.push({a, 'a'});
        if (b) maxHeap.push({b, 'b'});
        if (c) maxHeap.push({c, 'c'});
        pair<int, char> prev = maxHeap.top();
        maxHeap.pop();
        for (int i = 0; i < min(2, prev.first); i++) ans += prev.second;
        while (!maxHeap.empty()) {
            pair<int, char> temp = maxHeap.top();
            maxHeap.pop();
            for (int i = 0; i < min(2, temp.first); i++) ans += temp.second;
            prev.first -= 2;
            if (prev.first > 0) maxHeap.push(prev);
            prev = temp;
        }
        return ans;
    }
};