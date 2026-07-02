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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        // TreeNode* curr = root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> layer;
            int n = que.size();
            layer.reserve(n);
            for(int i=0; i<n; i++){
                TreeNode* temp = que.front();
                que.pop();
                layer.push_back(temp->val);
                if(temp->left != nullptr){
                    que.push(temp->left);
                }
                if(temp->right != nullptr){
                    que.push(temp->right);
                }
            }
            ans.push_back(move(layer));
        }
        return ans;
    }
};
