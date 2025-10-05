// Last updated: 10/5/2025, 9:00:01 AM
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
    vector<string> res;

public:
    void find(TreeNode* root, string path) {
        if (root == nullptr) {
            return;
        }

        // Convert the integer value to a string
        string str = to_string(root->val);

        // If the current node is a leaf, add the current path to the result
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path + str);
            return;
        }

        // If not a leaf, continue to the left and right children
        // Append the current node value to the path
        find(root->left, path + str + "->");
        find(root->right, path + str + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        find(root, path);
        return res;
    }
};
