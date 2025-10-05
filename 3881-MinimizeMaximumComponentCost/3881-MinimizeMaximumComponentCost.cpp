// Last updated: 10/5/2025, 8:48:44 AM
class Solution {
public:

   void dfs(int node , vector<vector<int>>& adj, vector<bool>& visited)
   {
    visited[node]=true ; 
    for(int &v : adj[node])
    {
        if(!visited[v])
        {
            dfs(v , adj , visited) ;
        }
    }
   }
   bool solve(int n, vector<vector<int>>& edges, int k , int mid)
   {
    vector<vector<int>>adj(n); // graph bna lo for this 
    vector<bool>visited(n,false); // dfs 
    for(auto &edge:edges)
    {
        int u = edge[0] ; 
        int v = edge[1] ; 
        int w = edge[2] ;

        if (w <= mid) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int count = 0 ; 

    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[i])
        {
            count++ ; 
            dfs(i,adj , visited) ; 
        }

    }
    return count<=k;

   }

    int minCost(int n, vector<vector<int>>& edges, int k) {

        int low = 0 ; 
        int high = 0 ; 
        for(auto& edge : edges)
        {
            high = max(high , edge[2]) ; 
        }
        int ans = high ; 

        while(low<=high)
        {
            int mid = low+(high-low)/2 ; 
            if(solve(n , edges , k , mid))
            {
                ans = mid ; 
                high = mid-1 ; 
            }
            else
            {
                low = mid+1 ; 
            }
        }
        return ans ; 
         
    }
};