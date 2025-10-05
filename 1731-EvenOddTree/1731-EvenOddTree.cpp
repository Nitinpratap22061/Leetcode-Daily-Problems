// Last updated: 10/5/2025, 8:54:41 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int prevseen =(level % 2 == 0) ? INT_MIN : INT_MAX;
            int n = q.size();
            while (n--) {
                auto node = q.front();
                q.pop();
                if (level % 2 == 0) {
                    if (node->val % 2 == 0 || prevseen >= node->val) {
                        return false;
                    }
                    
                } else {
                    if (node->val % 2 != 0 || prevseen <= node->val) {
                        return false;
                    }
                }
                prevseen = node->val ; 
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            level++;
        }
        return true;
    }
};