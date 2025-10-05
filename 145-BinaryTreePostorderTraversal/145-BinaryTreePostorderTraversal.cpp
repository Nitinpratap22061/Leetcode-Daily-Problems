// Last updated: 10/5/2025, 9:00:52 AM
#include <vector>


class Solution {
public:
    void postorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
