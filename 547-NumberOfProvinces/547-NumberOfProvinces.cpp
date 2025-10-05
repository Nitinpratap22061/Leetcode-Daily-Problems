// Last updated: 10/5/2025, 8:58:40 AM
class Solution {
public:
      void dfs(unordered_map<int, vector<int>>&adj , int u , vector<bool>&visited)
      {
        visited[u] = true;
        for(int &v : adj[u])
        {
            if(!visited[v])
            {
                dfs(adj , v , visited);
            }
        }
      }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // s-1 graph bano to visualize
        unordered_map<int, vector<int>> adj;
        int v = isConnected.size();
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //normal dfs lagake count
        vector<bool>visited(v,false) ; 
        int count = 0 ;
        for(int i =0 ; i<v ; i++)
        {
            if(!visited[i])
            {
                dfs(adj,i , visited) ; 
                count++ ;
            }
        }
        return count ; 


    }
};