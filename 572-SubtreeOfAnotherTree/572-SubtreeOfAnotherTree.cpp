// Last updated: 10/5/2025, 8:58:33 AM
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
    bool same(TreeNode* root1 , TreeNode* root2)
    {
        if(!root1 && !root2)
        {
            return true;
        }
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        if(root1->val==root2->val && same(root1->left , root2->left) && same(root1->right , root2->right))
        {
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
        {
            return false;
        }
        if(!subRoot)
        {
            return true;
        }
        if(same(root , subRoot))
        {
            return true;
        }
        return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);

        
    }
};