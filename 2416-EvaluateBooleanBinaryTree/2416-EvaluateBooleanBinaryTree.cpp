// Last updated: 10/5/2025, 8:52:24 AM
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
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right)
        {
            return root->val;
        }
        int ansLeft=evaluateTree(root->left);
        int ansRight=evaluateTree(root->right);
        if(root->val==2)
        {
            return ansLeft | ansRight;
        }
        return ansLeft & ansRight;
        
    }
};