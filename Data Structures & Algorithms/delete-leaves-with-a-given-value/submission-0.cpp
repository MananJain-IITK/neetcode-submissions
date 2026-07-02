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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root,target);
        if(root && root->val==-1) return nullptr;
        return root;
    }
private:
    void dfs(TreeNode* root, int target){
        if(root->left) dfs(root->left, target);
        if(root->right) dfs(root->right, target);
        if (root->right && root->right->val==-1) root->right = nullptr;
        if(root->left && root->left->val==-1) root->left = nullptr;
        if(!(root->left)&&!(root->right)&&root->val==target){
            root->val=-1;
        }
        
        return;
    }
};