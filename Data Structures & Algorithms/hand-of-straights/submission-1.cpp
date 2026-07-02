class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // 1. Base case: If the cards can't divide evenly, impossible.
        if (hand.size() % groupSize != 0) return false;

        // 2. Build the Frequency Map (Automatically sorts the keys!)
        map<int, int> counts;
        for (int card : hand) {
            counts[card]++;
        }

        // 3. Iterate through our sorted unique cards
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            int startCard = it->first;
            int count = it->second;

            // If we have cards of this value left, we MUST start groups with them!
            if (count > 0) {
                
                // Try to build the consecutive sequence
                for (int i = 0; i < groupSize; i++) {
                    int currentCard = startCard + i;
                    
                    // Do we have enough of the next consecutive card to finish these groups?
                    if (counts[currentCard] < count) {
                        return false; 
                    }
                    
                    // Deduct the cards we just used!
                    counts[currentCard] -= count;
                }
            }
        }

        return true;
    }
};
