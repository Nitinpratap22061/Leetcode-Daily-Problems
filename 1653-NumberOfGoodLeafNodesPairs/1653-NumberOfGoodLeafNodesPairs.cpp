// Last updated: 10/5/2025, 8:54:55 AM
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

    void makeGraph(TreeNode* root , TreeNode* prevNode ,unordered_map<TreeNode* , vector<TreeNode*>>& mp ,unordered_set<TreeNode*>&st )
    {
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            //leaf
            st.insert(root);
        }
        if(prevNode!=NULL)
        {
            mp[root].push_back(prevNode);
            mp[prevNode].push_back(root);
        }
        makeGraph(root->left,root,mp,st);
        makeGraph(root->right,root,mp,st);

    }
    int countPairs(TreeNode* root, int distance) {
       //graph
       unordered_map<TreeNode* , vector<TreeNode*>> mp;
        unordered_set<TreeNode*>st;
        makeGraph(root,NULL,mp,st); // graph bn gya and leaf node set bhi
        int count = 0 ;
        for(auto &leaf:st)
        {
            //bfs
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(leaf);
            visited.insert(leaf);
            
            for(int level = 0 ; level<=distance ; level++)
            {
                int n = q.size();
                while(n--)
                {
                    auto curr = q.front();
                    q.pop();
                    if(curr!=leaf && st.count(curr))
                    {
                        count++;
                    }
                    for(auto &ngbr : mp[curr])
                    {
                        if(!visited.count(ngbr))
                        {
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
                

            }
        }
            
         return count/2;   

        
    }
};