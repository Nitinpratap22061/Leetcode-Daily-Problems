// Last updated: 10/5/2025, 8:58:52 AM
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
int maxD=-1;
int res;
   void dfs(TreeNode* root , int level)
   {
    if(!root)
    {
        return ;
    }
    if(level>maxD)
    {
        maxD = level;
        res = root->val;
    }
    dfs(root->left , level+1);
    dfs(root->right,level+1);
   }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};