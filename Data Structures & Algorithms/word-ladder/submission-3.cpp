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
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited;

        int ans = 1;
        while (!que.empty()) {
            int qn = que.size();

            // if(ans>n+1) return 0;
            while (qn--) {
                string word = que.front();
                que.pop();

                if (word == endWord) return ans;
                // for () {
                    for (int j = 0; j < n; j++) {
                        string tempt = word;
                        tempt[j] = '*';
                        for(int i = 0; i < connectors[tempt].size(); i++)
                        if (visited.find(connectors[tempt][i]) == visited.end()) {
                            que.push(connectors[tempt][i]);
                            visited.insert(connectors[tempt][i]);
                        }
                    }
                // }
            }
            ans++;
        }
        return 0;
    }
};
