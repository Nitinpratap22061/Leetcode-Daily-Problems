// Last updated: 10/5/2025, 9:00:23 AM
class Solution {
public:

bool isCycleDfs( unordered_map<int,vector<int>>&adj , int u , vector<bool>&visited , vector<bool>& inrecc)
{
    visited[u] = true ; 
    inrecc[u] = true ; 
    for(int &v:adj[u])
    {
        if(!visited[v])
        {
           if( isCycleDfs(adj,v,visited,inrecc))
           {
            return true;
           }
        }
        else if(inrecc[v])
        {
            return true;
        }
    }
    inrecc[u] = false;
    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //graph bano 
        unordered_map<int,vector<int>>adj;
      for(auto &vec:prerequisites)
      {
        int u =vec[0];
        int v = vec[1];

        adj[v].push_back(u);
      }

      //simply directed cyclic nhi honi chahiye let do by dfs ; 
      int n = numCourses;
      vector<bool>visited(n,false) ; 
      vector<bool>inrecc(n,false) ; 
      for(int i = 0 ; i<n ; i++)
      {
          if(!visited[i] && isCycleDfs(adj , i , visited , inrecc))
          {
            return false ; 
          }
        
      }
      return true;
      

      
        
        
    }
};