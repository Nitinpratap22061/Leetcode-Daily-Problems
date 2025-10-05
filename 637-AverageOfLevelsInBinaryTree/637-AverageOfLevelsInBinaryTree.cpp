// Last updated: 10/5/2025, 8:58:18 AM
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>result;
        double ans;
        double avglevelsum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
        int node=q.size();
        double divisor=q.size();
        avglevelsum=0;
        while(node--){
            TreeNode* currentNode=q.front();
            q.pop();
            if(currentNode->left){
                q.push(currentNode->left);
            }
            if(currentNode->right){
                q.push(currentNode->right);
            }
            avglevelsum=(avglevelsum+currentNode->val);
        }
        ans=avglevelsum/divisor;
        result.push_back(ans);
        }
        return result;
        
    }
};