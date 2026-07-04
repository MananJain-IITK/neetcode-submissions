class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_map<string, vector<string>> connectors;
        for (string word : wordList) {
            for (int i = 0; i < n; i++) {
                string temp = word;
                temp[i] = '*';
                connectors[temp].push_back(word);
            }
        }
        queue<pair<string, string>> que;
        for (int i = 0; i < n; i++) {
            string temp = beginWord;
            temp[i] = '*';
            que.push({beginWord, temp});
        }
        unordered_set<string> visited;

        int ans = 1;
        while (!que.empty()) {
            int qn = que.size();

            // if(ans>n+1) return 0;
            while (qn--) {
                pair<string, string> temp = que.front();
                que.pop();
                string word = temp.first;
                string connector = temp.second;

                if (word == endWord) return ans;
                for (int i = 0; i < connectors[connector].size(); i++) {
                    for (int j = 0; j < n; j++) {
                        string tempt = connectors[connector][i];
                        tempt[j] = '*';
                        if (visited.find(tempt) == visited.end()) {
                            que.push({connectors[connector][i], tempt});
                            visited.insert(tempt);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
