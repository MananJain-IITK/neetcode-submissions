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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->right == nullptr && root->left == nullptr) return 1;
        queue<TreeNode*> que;
        int maxLeft = root->val;
        int maxRight = root->val;
        int ans = 0;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            for(int i = 0; i < n; i++){
                TreeNode* temp = que.front();
                que.pop();
                if (temp->left != nullptr) {
                    if(temp->left->val >= maxLeft) ans+=1;
                    maxLeft = max(maxLeft, temp->left->val);
                    que.push(temp->left);
                }

                if (temp->right != nullptr) {
                    if(temp->right->val >= maxRight) ans+=1;
                    maxRight = max(maxRight, temp->right->val);
                    que.push(temp->right);
                }
            }
        }
        return ans;
    }
};
