class TrieNode{
public: 
    TrieNode* children[26];
    bool endOfWord;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. Build the Trie (Your code here was perfect!)
        TrieNode* root = new TrieNode();
        for(string s: words){
            TrieNode* curr = root;
            for(char c: s){
                int i = c - 'a';
                if(curr->children[i] == nullptr){
                    curr->children[i] = new TrieNode();
                }
                curr = curr->children[i];
            }
            curr->endOfWord = true;
        }
        
        vector<string> ans;
        string currPath = "";
        
        // 2. Launch DFS from EVERY cell on the board
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                backtrack(board, root, ans, currPath, r, c);
            }
        }
        return ans;
    }

private:
    void backtrack(vector<vector<char>>& board, TrieNode* curr, vector<string>& ans, string& currPath, int r, int c){
        // 1. Check bounds AND check if it's already visited ('#')
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') {
            return;
        }
        
        // 2. See if the current board letter exists in the Trie
        char ch = board[r][c];
        int i = ch - 'a';
        if (curr->children[i] == nullptr) {
            return; // Dead end in the Trie, prune this branch instantly!
        }
        
        // 3. Move down the Trie and add to our path
        curr = curr->children[i];
        currPath.push_back(ch);
        
        // 4. Did we just form a complete word?
        if (curr->endOfWord) {
            ans.push_back(currPath);
            curr->endOfWord = false; // Prevent duplicates if we find this word again!
            // Notice: NO RETURN STATEMENT HERE. We keep digging!
        }
        
        // 5. CHOOSE: Mark cell as visited
        board[r][c] = '#';
        
        // 6. EXPLORE: 4-Way DFS
        backtrack(board, curr, ans, currPath, r + 1, c); // Down
        backtrack(board, curr, ans, currPath, r - 1, c); // Up
        backtrack(board, curr, ans, currPath, r, c + 1); // Right
        backtrack(board, curr, ans, currPath, r, c - 1); // Left
        
        // 7. UNCHOOSE: Restore the cell and the path string
        board[r][c] = ch;
        currPath.pop_back();
    }
};