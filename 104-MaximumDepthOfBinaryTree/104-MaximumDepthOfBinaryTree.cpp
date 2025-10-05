// Last updated: 10/5/2025, 9:01:32 AM
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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->right==NULL && root->left==NULL)//leaf node
        {
            return 1;

        }

        int l=maxDepth(root->left);
        int r=maxDepth(root->right);

        return max(l,r)+1;
        
    }
};