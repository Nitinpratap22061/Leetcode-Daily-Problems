// Last updated: 10/5/2025, 8:55:09 AM
class Solution {
public:
 int count = 0 ;

 void dfs(int u,vector<bool>&visited,unordered_map<int,vector<pair<int,int>>>&adj)
 {
    visited[u]=true;
    for(auto &v:adj[u])
    {
        int p = v.first;
        int check = v.second;
        if(!visited[p])
        {
            if(check==1)
            {
                count++;
            }
            dfs(p,visited,adj);
        }

    }
 }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:connections)
        {
            int a = vec[0];
            int b = vec[1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});
        }
        vector<bool>visited(n,false);

        dfs(0,visited,adj);

        return count;


        
    }
};