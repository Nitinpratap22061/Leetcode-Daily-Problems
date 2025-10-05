// Last updated: 10/5/2025, 9:00:32 AM

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int>res;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            TreeNode* curr = NULL;
            while(n--)
            {
                 curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                }
                 if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            res.push_back(curr->val);
        }
        return res;
    }
};