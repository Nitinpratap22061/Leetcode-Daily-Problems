// Last updated: 10/5/2025, 8:58:34 AM
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
int help(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    int sum=root->val;
    sum+=help(root->left) + help(root->right);
    return sum;
}
    int findTilt(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int sum= abs( help(root->left) - help(root->right) );
        sum+=findTilt(root->left) + findTilt(root->right);

        return sum;

        
    }
};