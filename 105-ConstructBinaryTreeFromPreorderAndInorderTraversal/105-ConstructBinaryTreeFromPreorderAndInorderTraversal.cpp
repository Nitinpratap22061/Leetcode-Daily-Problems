// Last updated: 10/5/2025, 9:01:31 AM
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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int start , int end , int &idx)
    {
        if(start>end) return NULL;
        int root = preorder[idx];
        int i = start ; 
        for(;i<=end;i++)
        {
            if(inorder[i]==root)
            {
                break;
            }
        }
        idx++ ; 
        TreeNode* rootval = new TreeNode(root) ; 
        rootval->left = solve(preorder , inorder , start , i-1 , idx);
        rootval->right = solve(preorder , inorder , i+1,end,idx) ; 


        return rootval;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int  n = preorder.size() ; 
        int idx =0 ;
        return solve(preorder , inorder , 0 , n-1 , idx) ;
        
    }
};