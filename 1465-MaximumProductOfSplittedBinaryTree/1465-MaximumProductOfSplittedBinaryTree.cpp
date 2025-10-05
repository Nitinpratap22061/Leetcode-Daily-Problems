// Last updated: 10/5/2025, 8:55:32 AM

class Solution {
public:
    long long SUM = 0;
    long long maxp = 0;
    const int MOD = 1e9 + 7;

    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long find(TreeNode* root) {
        if (!root) return 0 ;
        long long lsum = find(root->left);
        long long rsum = find(root->right);
        long long s1 = root->val + lsum + rsum;
        long long s2 = SUM - s1;
        maxp = max(maxp, s1 * s2);
        return s1;
    }

    int maxProduct(TreeNode* root) {
        SUM = totalSum(root);
        find(root);
        return maxp % MOD;
    }
};
