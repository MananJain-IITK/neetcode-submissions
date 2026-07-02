#include <algorithm>
#include <utility>

using namespace std;

// Assuming TreeNode is defined

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        // The answer is the absolute max of the root's two possible realities
        return max(result.first, result.second);
    }

private:
    // Returns a pair: {Max profit if ROBBED, Max profit if SKIPPED}
    pair<int, int> dfs(TreeNode* root) {
        // Base case: A null node yields 0 profit regardless of choice
        if (!root) return {0, 0};

        // 1. Post-Order Traversal: Get the states of our children first
        pair<int, int> leftState = dfs(root->left);
        pair<int, int> rightState = dfs(root->right);

        // 2. Calculate option A: We ROB this node
        // We MUST skip our immediate children, so we add their "skipped" max profits
        int robCurrent = root->val + leftState.second + rightState.second;

        // 3. Calculate option B: We SKIP this node
        // We can either rob OR skip our children, so we take the absolute best from both
        int skipCurrent = max(leftState.first, leftState.second) + 
                          max(rightState.first, rightState.second);

        // 4. Return the calculated state pair up to our parent
        return {robCurrent, skipCurrent};
    }
};