// Last updated: 11/1/2025, 5:26:13 PM
class Solution {
public:
    int m , n ; 
    int count ; 
    vector<vector<int>>directions = {{1,0} , {0,-1} , {-1,0} , {0,1}} ; 
    void dfs(int i , int j , vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return ; 
        }
       
        if(grid[i][j]==0 || grid[i][j]=='$')
        {
            return ; 
        }

         grid[i][j]='$' ; 
         count++ ; 
         for(auto &dir:directions)
         {
            int u = i+dir[0] ; 
            int v = j+dir[1] ; 
            dfs(u , v , grid) ; 
         }
         return ; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size() ; 
        n= grid[0].size() ; 
        int ans = 0;
        

        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j]==1)
                {
                    count=0;
                    dfs(i , j , grid) ; 
                    ans = max(ans,count);

                }
            }
        }
        return ans ; 
        
    }
};