// Last updated: 10/5/2025, 8:58:47 AM
class Solution {
public:
    int res = 0; 

    int height(TreeNode* root) {
        if (!root) return 0;  

        int left = height(root->left);
        int right = height(root->right);

        res = max(res, left + right);  

        return 1 + max(left, right);  
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);  
        return res;    
    }
};
