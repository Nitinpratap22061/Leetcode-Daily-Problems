// Last updated: 10/5/2025, 8:58:10 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> findMax(vector<int>& nums, int start, int end) {
        int maxVal = INT_MIN;
        int idx = -1;
        for (int i = start; i < end; i++) {
            if (maxVal < nums[i]) {
                maxVal = nums[i];
                idx = i;
            }
        }
        return make_pair(maxVal, idx);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }

    TreeNode* construct(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nullptr;
        }

        // Finding the maximum and its index in the current range
        pair<int, int> maxPair = findMax(nums, start, end);
        int maxVal = maxPair.first;
        int idxreq = maxPair.second;

        TreeNode* root = new TreeNode(maxVal);

        // Recursively construct left and right subtrees
        root->left = construct(nums, start, idxreq);
        root->right = construct(nums, idxreq + 1, end);

        return root;
    }
};