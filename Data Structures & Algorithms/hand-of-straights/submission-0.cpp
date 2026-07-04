class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        int prev = 0;
        int curr = 1;
        sort(hand.begin(), hand.end());
        for(int i=0; i<n-1; i++){
            if(hand[i]== hand[i+1]){
                curr++;
            }else{
                if(curr<prev) return false;
                prev = curr;
                curr=1;
            }
        }
        return true;
    }
};
