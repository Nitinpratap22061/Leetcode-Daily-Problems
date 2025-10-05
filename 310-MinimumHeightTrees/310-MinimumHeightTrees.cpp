// Last updated: 10/5/2025, 8:59:43 AM
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            return {0};
        }
        vector<int>ans;
        //graph bnao 
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(n);
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        //now leaf find and bfs lagao to go to center
        queue<int>q;
        for(int i = 0 ; i<n ; i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        while(n>2)
        {
            int size = q.size();
            n-=size;
            while(size--)
            {
                int u = q.front();
                q.pop();
                for(int &v:mp[u])
                {
                    indegree[v]--;
                    if(indegree[v]==1)
                    {
                        q.push(v);
                    }
                }
            }
            
        }
        //q me result aa gya hoga
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};