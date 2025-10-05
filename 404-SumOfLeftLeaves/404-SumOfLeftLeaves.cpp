// Last updated: 10/5/2025, 8:59:14 AM
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
    int solve(TreeNode* root , TreeNode* parent)
    {
        if(!root) return 0 ; 
        if(root->left==NULL && root->right==NULL)//leaf
        {
            if(parent!=NULL && parent->left == root)
            {
                return root->val;
            }
        }
         int left = solve(root->left , root);
            int right = solve(root->right , root);
           return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,NULL);
        
    }
};