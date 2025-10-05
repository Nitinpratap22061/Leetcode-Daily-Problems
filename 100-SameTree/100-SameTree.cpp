// Last updated: 10/5/2025, 9:01:37 AM
class Solution {
public:
    vector<int> bfs(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode*> q;
        
        if (!root) return ans;  

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {  
                TreeNode* curr = q.front();
                q.pop();

                if (curr) {
                    ans.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                } else {
                    ans.push_back(-101);  
                }
            }
        }
        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return bfs(p) == bfs(q);
    }
};
