// Last updated: 11/1/2025, 4:40:34 PM
class Solution {
public:
    int m ; 
    int n ; 

       

    int solve(int i , int j , vector<vector<int>>& grid ,  vector<vector<bool>>&visited )
    {
    if(i<0 || j<0 || i>=m || j>=n)
    {
          return 1 ; 
    }
    if(grid[i][j]==0)
    {
        return 1 ; 
    }
    if(visited[i][j])
    {
        return 0 ; 
    }
    visited[i][j] = true ; 
     //dfs maar do 
     int up =  solve(i-1 , j , grid , visited) ; 
     int down = solve(i+1, j , grid , visited) ; 
     int right = solve(i , j+1 , grid , visited) ; 
     int left = solve(i , j-1 , grid , visited) ; 

     return up+down+left+right ; 
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size() ; 
        n = grid[0].size() ; 

        vector<vector<bool>>visited(m , vector<bool>(n,false)) ;
         

        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    return solve(i , j , grid , visited) ; 
                    
                }
            }
        }
        return -1 ; 
        
    }
};