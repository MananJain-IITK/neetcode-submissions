class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        int dict[26] = {0};
        for (int i = 0; i < order.size(); i++) {
            dict[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            for (int j = 0; j < word1.size(); j++) {
                if (j == word2.size()) return false;
                if (word1[j] != word2[j]) {
                    if (dict[word1[j] - 'a'] > dict[word2[j] - 'a']) return false;
                    break;
                }
            }
        }
        return true;
    }
};
