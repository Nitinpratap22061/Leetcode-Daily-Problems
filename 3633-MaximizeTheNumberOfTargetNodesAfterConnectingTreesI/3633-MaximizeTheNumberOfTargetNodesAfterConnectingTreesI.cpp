// Last updated: 10/5/2025, 8:49:30 AM
class Solution {
public:
     

     int bfs(int curr , unordered_map<int,vector<int>>& adj , int dist,int n)
     {
        queue<pair<int,int>>q;
        q.push({curr,0});
        vector<bool>visited(n,false);
        visited[curr]=true;
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front().first;
            int distance = q.front().second;
            q.pop();
            if(distance>dist)
            {
                continue;
            }
         count++;
            for(auto &ngbr:adj[curr])
            {
                if(!visited[ngbr])
                {
                    visited[ngbr]=true;
                    q.push({ngbr,distance+1});
                }
            }
        }
        return count;
     }

     vector<int>findCount(vector<vector<int>>& edges , int d)
     {
        //adjecency list bna lo
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //bfs
        int n = edges.size()+1;
        vector<int>result(n);
        for(int i=0 ; i<n ; i++ )
        {
            result[i] = bfs(i,adj,d,n);
        }
        return result;
     }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
     
        vector<int>res1 = findCount(edges1,k);
        vector<int>res2= findCount(edges2,k-1);

        int maxi = *max_element(begin(res2),end(res2));

        for(int i=0 ; i<res1.size();i++)
        {
            res1[i]+=maxi;
        }

        return res1;
        
    }
};