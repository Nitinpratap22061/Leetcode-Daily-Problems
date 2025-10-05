// Last updated: 10/5/2025, 8:51:39 AM
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        vector<long long>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
           long long n = q.size();
           long long sum =0;
           while(n--)
           {
            TreeNode* node  = q.front();
            q.pop();
            sum+= (long long)node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
           }
           ans.push_back(sum);
            
        }
        sort(ans.begin() , ans.end());
         if (k > ans.size() || k <= 0) return -1;
        long long n=ans.size();
        return ans[n-k];

        
    }
};