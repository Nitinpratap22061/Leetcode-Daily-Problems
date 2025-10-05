// Last updated: 10/5/2025, 8:58:12 AM

class Solution {
public:
string getsubstringtree(TreeNode* root,vector<TreeNode*>&res,unordered_map<string,int>&mp)
{
    if(root==NULL){
        return "N";
    }
string s=to_string(root->val)+" ,"+getsubstringtree(root->left,res,mp)+" , "+getsubstringtree(root->right,res,mp);
    if(mp[s]==1){
        res.push_back(root);
    }
    
mp[s]++;
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
     vector<TreeNode*>res;
     unordered_map<string,int>mp;
     getsubstringtree(root,res,mp);
     return res;   
    }
};