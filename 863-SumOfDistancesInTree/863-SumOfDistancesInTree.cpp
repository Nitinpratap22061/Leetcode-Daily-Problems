// Last updated: 10/5/2025, 8:57:34 AM
class Solution {
public:
      long root_result = 0 ;
      vector<int>count ; 
      int N;

      void dfs(unordered_map<int,vector<int>>&adj ,int parent_node , int prev_node , vector<int>&result )
      {
        for(int &child : adj[parent_node])
        {
            if(child==prev_node)
            {
                continue;
            }
            result[child] = result[parent_node] - count[child] + (N-count[child]) ; 
            dfs(adj,child,parent_node,result);
        }
      }

      int dfsRoot(unordered_map<int,vector<int>>&adj , int curr_node , int prev_node , int curr_depth)
      {
         int total_count = 1 ; //count ke lie
         root_result +=curr_depth;
         for(int &child : adj[curr_node])
         {
            if(child==prev_node)
            {
                continue;
            }
            total_count+=dfsRoot(adj,child,curr_node,curr_depth+1);
         }
         count[curr_node] = total_count ;//so count to rakh liye ho gya
         return total_count ; 
      }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n ; 
        count.resize(n,0) ; 
        //graph
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //root ke liye find ans and count of node of subtree of root and itself 
        dfsRoot(adj,0,-1,0);
        vector<int>result(n,0) ; 
        result[0] = root_result ; 

        //2nd dfs to find all to fill result ; 
        dfs(adj , 0 , -1 , result) ;
        return result;
        
    }
};