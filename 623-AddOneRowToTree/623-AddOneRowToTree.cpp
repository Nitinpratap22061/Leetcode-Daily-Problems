// Last updated: 10/5/2025, 8:58:23 AM
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //bfs
        if(depth==1)
        {
            return new TreeNode(val,root,nullptr);
        }
         queue<TreeNode*>q;
         q.push(root);
         int level = 1 ; 
         while(!q.empty())
         {
            int n = q.size();
            
            while(n--)
            {
                auto curr = q.front();
                q.pop();

                if(level ==depth-1)
                {
                    //create new node
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    newLeft->left = curr->left;
                    newRight->right = curr->right;

                    curr->left = newLeft;
                    curr->right = newRight;

                }
                else
                {
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                }

            }
            level++;
            
         }
         return root;
        
        
    }
};