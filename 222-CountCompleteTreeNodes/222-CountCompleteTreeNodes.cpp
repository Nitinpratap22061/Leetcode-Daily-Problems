// Last updated: 10/5/2025, 9:00:14 AM
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
    int getleftheight(TreeNode* root)
    {
        int count=0;
        if(root==NULL)
        {
            return 0;
        }
        TreeNode* temp=root;
        while(temp){
            count++;
            temp=temp->left;
        }
        return count;
    }
    int getrightheight(TreeNode* root)
    {
        int count=0;
        if(root==NULL)
        {
            return 0;
        }
        TreeNode* temp=root;
        while(temp){
            count++;
            temp=temp->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh=getleftheight(root);
        int rh=getrightheight(root);
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;

        
    }
};