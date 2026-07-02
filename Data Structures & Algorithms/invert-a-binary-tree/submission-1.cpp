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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        queue<TreeNode*> inv;
        inv.push(root);
        while(!inv.empty()){
            TreeNode* node = inv.front();
            inv.pop();
            swap(node->left, node->right);
            if(node->left) inv.push(node->left);
            if(node->right) inv.push(node->right);
        }
        return root;
    }
};
