// Last updated: 10/5/2025, 9:01:33 AM
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        deque<TreeNode*> dq;
        dq.push_front(root);
        bool reverse = false;

        while (!dq.empty()) {
            vector<int> ans;
            int node = dq.size();

            while (node--) {
                if (!reverse) {
                    TreeNode* current = dq.front();
                    dq.pop_front();
                    if (current->left) {
                        dq.push_back(current->left);
                    }
                    if (current->right) {
                        dq.push_back(current->right);
                    }
                    ans.push_back(current->val);
                } else {
                    TreeNode* curr = dq.back();
                    dq.pop_back();
                    if (curr->right) {
                        dq.push_front(curr->right);
                    }
                    if (curr->left) {
                        dq.push_front(curr->left);
                    }
                    ans.push_back(curr->val);
                }
            }
            reverse = !reverse;
            res.push_back(ans);
        }

        return res;
    }
};
