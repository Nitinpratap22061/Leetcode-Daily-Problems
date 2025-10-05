// Last updated: 10/5/2025, 9:01:14 AM
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
    int maxsum ;
    int  solve(TreeNode* root)
    {
        if(!root) return 0 ;
        int l = solve(root->left);
        int r = solve(root->right);
        int both_good = l+r+root->val;
        int one_good = max(l,r)+root->val;
        int root_good = root->val;
        maxsum = max({maxsum , both_good , one_good , root_good});
        return max({one_good , root_good});
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        int ans=solve(root);
        cout<<ans;
        return maxsum;
        
    }
};