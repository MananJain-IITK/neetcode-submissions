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
    int maxPathSum(TreeNode* root) {
        gainFromSubtree(root);
        return maxSum;
    }

private:
    int maxSum = INT_MIN; 
    int gainFromSubtree(TreeNode* node){
        if(node == nullptr) return 0;

        int leftGain = gainFromSubtree(node->left);
        int rightGain = gainFromSubtree(node->right);

        maxSum = max(maxSum, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain); 
    }
};
