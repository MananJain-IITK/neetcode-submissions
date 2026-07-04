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
    int rob(TreeNode* root) {
        // int ans=0;
        return dfs(root);
        // return ans;
    }

   private:
    int dfs(TreeNode*& root) {
        if (!root) return 0;
        // ans+=root->value;
        if (!(root->left) && (!root->right)) {
            return root->val;
        }
        int n1 =root->val;
        if(root->left) n1+=dfs(root->left->left) + dfs(root->left->right);
        if(root->right) n1 += dfs(root->right->left) + dfs(root->right->right);

        int n2 =0;
        n2 = dfs(root->left) + dfs(root->right);

        return max(n1,n2);
    }
};