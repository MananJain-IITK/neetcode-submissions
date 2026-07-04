class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights(stones.begin(), stones.end());
        while(weights.size() >= 1){
            int x = weights.top();
            weights.pop();
            int y = weights.top();
            weights.pop();
            if(x!=y) weights.push(x-y);
        }
        if(!weights.empty()) return weights.top();
        return 0;
    }
};
