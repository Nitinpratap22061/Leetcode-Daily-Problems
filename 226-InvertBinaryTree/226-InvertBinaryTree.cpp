// Last updated: 10/5/2025, 9:00:13 AM
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

     
    TreeNode* invertTree(TreeNode* root) {

        if(root==NULL){
             return NULL;
         }
        TreeNode* left =  invertTree(root->left);
         TreeNode* right = invertTree(root->right);

         TreeNode* t= left;
         root->left=right;
         root->right=t;

         return root;
        
        
    }
};