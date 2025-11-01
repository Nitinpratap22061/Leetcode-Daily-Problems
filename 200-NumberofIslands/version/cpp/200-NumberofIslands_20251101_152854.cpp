// Last updated: 11/1/2025, 3:28:54 PM
class Solution {
public:
     int m,n;
      vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}} ; 

      bool isSafe(int i , int j)
      {
         if(i<0 || j<0 || i>=m || j>=n)
         {
            return false ; 
         }
         return true ; 
      }
     void solve(int i , int j , vector<vector<char>>& grid  ,  vector<vector<bool>>& visited)
     {
        if(grid[i][j]=='0' || visited[i][j])
        {
            return ; 
        }
         visited[i][j] = true ; 
        for(auto &dir:directions)
        {
            int u = i+dir[0] ; 
            int v = j+dir[1] ; 

            if(isSafe(u ,v) && !visited[u][v])
            {
                solve(u , v , grid , visited) ; 
            }
        }
        return  ; 

     }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;

        //1--land and 0--water 

        vector<vector<bool>>visited(m , vector<bool>(n,false)) ; 
        int count = 0 ; 

        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0  ; j<n ; j++)
            {
                if(grid[i][j]=='1'&&!visited[i][j])
                {
                    solve(i , j , grid , visited) ; 
                    count++  ; 
                }
            }
        }

        return count ; 

    }
};