// Last updated: 10/5/2025, 9:01:35 AM
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<vector<int>>ans2;

       TreeNode* currentNode;
             if(root==NULL){
                 return ans;
             }
             queue<TreeNode*>q;
             q.push(root);
             while(!q.empty()){
                 int node=q.size();
                vector<int>ans1;
                 while(node--){
                      currentNode=q.front();
                     q.pop();
                     if(currentNode->left){
                         q.push(currentNode->left);
                     }
                     if(currentNode->right){
                         q.push(currentNode->right);
                     }
                     
                     ans1.push_back(currentNode->val);
                 }

                     ans.push_back(ans1);
             }
                    //  reverse(ans.begin(),ans.end());

             return ans ;
        
    }
};