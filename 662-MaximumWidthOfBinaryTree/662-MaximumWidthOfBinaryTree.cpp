// Last updated: 10/5/2025, 8:58:09 AM
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
      typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll max_width=0;
        while(!q.empty()){
            ll l=q.front().second;
            ll r=q.back().second;
            max_width=max(max_width,r-l+1);
            int size=q.size();
            while(size--){
                TreeNode* current=q.front().first;
                ll idx=q.front().second;
                q.pop();
                if(current->left){
                    q.push({current->left,(2*idx)+1});
                }
                if(current->right){
                    q.push({current->right,(2*idx)+2});
                }
            }
        }
        return max_width;
        
    }
};