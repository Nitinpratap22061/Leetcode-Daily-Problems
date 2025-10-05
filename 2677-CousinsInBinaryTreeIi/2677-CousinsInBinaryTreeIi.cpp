// Last updated: 10/5/2025, 8:51:37 AM
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr; // Edge case: empty tree
        
        vector<int> lsum;
        queue<TreeNode*> q;
        q.push(root);

        // First pass: Compute level sums
        while (!q.empty()) {
            int n = q.size();
            int currSum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                currSum += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            lsum.push_back(currSum);
        }

        // Second pass: Update node values
        q.push(root);
        root->val = 0;
        int i = 1; // Start from level 1
        while (!q.empty() && i < lsum.size()) {
            int n = q.size();
            for (int j = 0; j < n; j++) {
                TreeNode* curr = q.front();
                q.pop();
                int siblingSum = 0;
                
                if (curr->left) siblingSum += curr->left->val;
                if (curr->right) siblingSum += curr->right->val;
                
                if (curr->left) {
                    curr->left->val = lsum[i] - siblingSum;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = lsum[i] - siblingSum;
                    q.push(curr->right);
                }
            }
            i++; 
        }

        return root;
    }
};
