// Last updated: 10/5/2025, 8:56:34 AM
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
int maxi=-1;
void findmax(TreeNode* root,TreeNode* child)
{
    if(!root || ! child)
    {
        return;
    }
    maxi=max(maxi,abs((root->val)-(child->val)));
    findmax(root,child->left);
    findmax(root,child->right);

}
void find(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    findmax(root,root->left);
    findmax(root,root->right);

    find(root->left);
    find(root->right);


}
    int maxAncestorDiff(TreeNode* root) {

        if(!root)
        {
            return 0;
        }
        find(root);

        return maxi;


        
    }
};