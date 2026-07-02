class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Convert the vectors to spans and pass them to the helper
        return helper(preorder, inorder);
    }

private:
    TreeNode* helper(span<int> preorder, span<int> inorder) {
        // Base case: if the span is empty, there are no nodes to build
        if (preorder.empty()) return nullptr;

        // The first element of preorder is always the root
        TreeNode* root = new TreeNode(preorder[0]);
        int n = inorder.size();
        if (n == 1) return root;

        // Find the root element inside the inorder span
        int i = 0;
        while (inorder[i] != preorder[0]) {
            i++;
        }

        // Corrected Slicing Logic
        root->left = helper(preorder.subspan(1, i), 
                            inorder.subspan(0, i));
                            
        root->right = helper(preorder.subspan(1 + i, n - 1 - i), 
                             inorder.subspan(i + 1, n - 1 - i));

        return root;
    }
};