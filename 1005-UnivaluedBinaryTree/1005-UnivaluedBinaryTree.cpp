// Last updated: 10/5/2025, 8:56:52 AM
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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>result;
        q.push(root);
        while(!q.empty()){
                int size=q.size();
                while(size--){
                    TreeNode* current=q.front();
                    q.pop();
                    if(current->left){
                        q.push(current->left);
                    }
                    if(current->right){
                        q.push(current->right);
                    }
                    result.push_back(current->val);
                }
        }
        int count=0;
        for(int i=0;i<result.size()-1;i++){
            if(result[i]==result[i+1]){
                count++;
            }
            
        }
            if(count==result.size()-1){
                return true;
            }
            return false;
           
        
    }
};