// Last updated: 10/5/2025, 8:59:02 AM
class Solution {
public:
    int count = 0; 

    void solve(TreeNode* root ,  long long targetSum) {
        if (!root) return;

        targetSum -= root->val;
        if (targetSum==0) {
            count++;
        }

        solve(root->left ,  targetSum);
        solve(root->right ,  targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        solve(root , targetSum); 
        pathSum(root->left , targetSum); 
        pathSum(root->right , targetSum); 

        return count;
    }
};
