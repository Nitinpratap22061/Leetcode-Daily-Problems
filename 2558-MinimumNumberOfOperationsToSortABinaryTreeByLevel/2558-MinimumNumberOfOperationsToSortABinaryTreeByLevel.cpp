// Last updated: 10/5/2025, 8:51:56 AM
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
    int minSwaps(vector<int>&vec)
    {
        int swaps = 0 ;
        unordered_map<int,int>mp;
        vector<int>sorted(vec.begin() , vec.end());
        sort(sorted.begin(),sorted.end());
        for(int i = 0 ; i<vec.size();i++)
        {
            mp[vec[i]] = i ;
        }
        for(int i =0 ; i<vec.size() ; i++)
        {
            if(vec[i]==sorted[i])
            {
                continue;
            }
            int currIndex = mp[sorted[i]]; // sorted wali ki index vec me
            mp[vec[i]] = currIndex;
            mp[vec[currIndex]]=i;
            swap(vec[currIndex],vec[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res = 0 ; 
        while(!q.empty())
        {
            int n = q.size();
            vector<int>vec;
            while(n--)
            {
                auto curr = q.front();
                q.pop();
                vec.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res+=minSwaps(vec);
        }
        return res;
        
    }
};