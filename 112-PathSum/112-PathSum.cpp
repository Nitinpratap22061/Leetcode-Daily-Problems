// Last updated: 10/5/2025, 9:01:25 AM
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        if (root == nullptr) {
            return false;
        }
        sum=sum+root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if(sum==targetSum)
            {
                return true;
            }
            return false; 
        }
        bool leftPath = hasPathSum(root->left, targetSum - root->val);
        bool rightPath = hasPathSum(root->right, targetSum - root->val);

        // Return true if either left or right subtree has a path with the target sum.
        return leftPath || rightPath;
    }
};
