// Last updated: 10/5/2025, 8:52:08 AM
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
       void solve(TreeNode* l, TreeNode* r , int level)
       {
        if(!l || !r) return;
        if(level%2==1)
        {
            int temp = l->val;
            l->val = r->val;
            r->val=temp;
        }
        solve(l->left,r->right,level+1);
        solve(l->right,r->left,level+1);

       }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        solve(root->left,root->right,1);
        return root;
        
    }
};