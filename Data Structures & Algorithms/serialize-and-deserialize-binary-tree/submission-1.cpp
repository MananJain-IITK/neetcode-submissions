/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded = "";
        if(!root) return encoded;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            for(int i=0; i<n; i++){
                if(que.front() == nullptr){
                    que.pop();
                    encoded += "null";
                    encoded+= ",";
                    continue;
                }
                TreeNode* temp = que.front();
                que.pop();
                que.push(temp->left);
                que.push(temp->right);
                encoded += to_string(temp->val);
                encoded += ",";
            }
        }
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<string> nums;
        int n = data.size();
        for(int i=0; i<n; i++){
            string temp = "";
            while(data[i] != ','){
                temp.push_back(data[i]);
                i++;
            }
            nums.push_back(temp);
        }

        TreeNode* root = new TreeNode(stoi(nums[0]));
        queue<TreeNode*> que;
        que.push(root);
        int tr = 1;

        while(!que.empty()){
            // int n = que.size();
            // for(int i=0; i<n; i++){
                TreeNode* temp = que.front();
                que.pop();
                if(nums[tr] != "null"){
                    temp->left = new TreeNode(stoi(nums[tr]));
                    que.push(temp->left);
                }
                tr++;
                if(nums[tr] != "null"){
                    temp->right = new TreeNode(stoi(nums[tr]));
                    que.push(temp->right);
                }
                tr++;
            // }
        }
        return root;
    }
};
