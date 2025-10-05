// Last updated: 10/5/2025, 9:01:24 AM
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
    vector<vector<int>>res ; 
    void solve(TreeNode* root , int targetSum , vector<int>ans)
    {
        if(!root)
        {
            return ; 
        }
        ans.push_back(root->val);
        targetSum -= root->val ;
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == 0)
            {
               res.push_back(ans) ; 
               ans = {};
            }
        }
        solve(root->left , targetSum , ans);
        solve(root->right , targetSum ,ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        solve(root , targetSum , ans);
        return res;
        
    }
};