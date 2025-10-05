// Last updated: 10/5/2025, 9:00:31 AM
class Solution {
public:
    int m;
    int n ; 
    vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}};
    void dfs(vector<vector<char>>& grid , int i , int j)
    {
        grid[i][j] = '$' ;
        for(auto &dir:directions)
        {
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && grid[new_i][new_j]=='1')
            {
                dfs(grid,new_i , new_j);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
        int count = 0 ; 
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid , i , j);
                    count+=1;
                }
            }
        }
        return count;
        
    }
};