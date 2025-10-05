// Last updated: 10/5/2025, 8:56:32 AM
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
    int maxLevelSum(TreeNode* root) {
       
        vector< pair <int,int> > vect;
        queue<TreeNode*>q;
        q.push(root);
        int sum;
        int flag;
        int level=0;
        while(!q.empty()){
            sum=0;
            level++;
            int size=q.size();
            while(size--){
                TreeNode* current=q.front();
                q.pop();
                sum=sum+current->val;
                flag=level;
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }

                }
                vect.push_back(make_pair(sum,level));
        }
        int max=INT_MIN;
        int maxlevel=0;
        for(int i=0;i<vect.size();i++){
            if(max<vect[i].first){
                max=vect[i].first;
                maxlevel=vect[i].second;

            }

        }
        return maxlevel;

        
    }
};