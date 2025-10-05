// Last updated: 10/5/2025, 9:01:26 AM
class Solution {
public:
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL) 
            return 1;

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == 0 || right == 0)
            return 1 + left + right;

        return 1 + min(left, right);
    }

    int minDepth(TreeNode* root) {
        return solve(root);
    }
};
