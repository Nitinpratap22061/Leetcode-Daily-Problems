// Last updated: 10/5/2025, 8:57:26 AM
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
unordered_map<int,int>mp;
int maxd = 0;
void depth(TreeNode* root , int d)
{
    if(!root)
    {
        return ; 
    }
    maxd = max(maxd , d);
    mp[root->val] = d ;
    depth(root->left , d+1);
    depth(root->right , d+1);
}
TreeNode* lca(TreeNode* root)
{
    if(!root)
    {
        return NULL;
    }
    if(mp[root->val]==maxd)
    {
        return root;
    }
    TreeNode* l = lca(root->left);
    TreeNode* r = lca(root->right);
    if(l!=NULL && r!=NULL)
    {
        return root;
    }
    return l ? l : r;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         depth(root , 0); // sb node ka deth stored in map and also knows maxd;
        return lca(root);
        
    }
};