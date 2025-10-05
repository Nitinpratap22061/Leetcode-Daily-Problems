// Last updated: 10/5/2025, 8:58:07 AM
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
     int secondminval ;
     int ans;
     void solve1(TreeNode* root)
     {
        if(!root)
        {
            return ;
        }
        if(root->val > ans && (secondminval==-1||root->val<secondminval))
        {
            secondminval = root->val;
            return ;
        }
        solve1(root->left);
        solve1(root->right);
     }
    int findSecondMinimumValue(TreeNode* root) {
        secondminval = -1;
        ans=root->val;
        solve1(root) ; //secondminval update;
       return secondminval;

        
    }
};