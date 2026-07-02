class TrieNode {
   public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        int count = 26;
        while (count--) {
            children[count] = nullptr;
        }
        endOfWord = false;
    }
};

class WordDictionary {
   public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }

    bool search(string word) { return dfs(root, word, 0); }

   private:
    bool dfs(TrieNode* root, string word, int i) {
        TrieNode* curr = root;
        for (int j = i; j < word.size(); j++) {
            char c = word[j];
            if (c == '.') {
                for (TrieNode* child: curr->children) {
                    if(child!=nullptr && dfs(child, word, j+1)) return true;
                }
                return false;
            }else{
                if(curr->children[c-'a'] == nullptr) return false;
                curr = curr->children[c-'a'];
            }
        }
        return curr->endOfWord;
    }
};
