// Last updated: 10/5/2025, 8:57:27 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


      
    unordered_map<TreeNode* , TreeNode*>parent;
    void inorder(TreeNode* root)
    {
        if(!root) return;

        if(root->left)
            parent[root->left] = root;
        inorder(root->left);
        if(root->right)
            parent[root->right] = root;
        inorder(root->right);
    }

    void bfs(TreeNode* target,int k,vector<int>& result)
    {
        if(!target) return;
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        int level = 0 ;
        while(!q.empty())
        {
            int n = q.size();
            if(level==k)
            {
                break;
            }
            while(n--)
            {
                auto curr = q.front();
                q.pop();
                if(curr->left && !visited.count(curr->left->val))
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val))
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if(parent.count(curr) && !visited.count(parent[curr]->val))
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            level++;
        }

        while(!q.empty())
        {
            auto ele = q.front();
            q.pop();
            result.push_back(ele->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        vector<int>result;
        inorder(root);
        bfs(target,k,result);
        return result;
        
    }
};