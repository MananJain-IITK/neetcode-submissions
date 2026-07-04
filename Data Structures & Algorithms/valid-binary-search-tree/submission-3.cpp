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
    bool isValidBST(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n=que.size();
            for(int i=0; i<n; i++){
                TreeNode* temp = que.front();
                if(!isValid(temp)) return false;
                que.pop();
                if(temp->left != nullptr) que.push(temp->left);
                if(temp->right != nullptr) que.push(temp->right);
            }
        }
        return true;
    }

private:
    bool isValid(TreeNode* root){
        if(!root) return false;
        if(root->left != nullptr){
            if(root->left->val >= root->val) return false;
        }
        
        if(root->right != nullptr){
            if(root->right->val < =root->val) return false;
        }
        return true;
    }
};
