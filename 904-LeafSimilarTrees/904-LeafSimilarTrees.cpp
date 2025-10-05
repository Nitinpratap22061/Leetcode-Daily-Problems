// Last updated: 10/5/2025, 8:57:22 AM


class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }

    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) {
            return;
        }

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();

            if (!current->left && !current->right) {
                leaves.push_back(current->val);
            }

            if (current->right) {
                s.push(current->right);
            }

            if (current->left) {
                s.push(current->left);
            }
        }
    }
};
