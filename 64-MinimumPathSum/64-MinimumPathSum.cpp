// Last updated: 10/5/2025, 9:02:08 AM
class Solution {
public:
    int t[202][202];
    int solve(vector<vector<int>>& grid , int  i , int j )
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i>=m || j>=n)
        {
            return 1e9;
        }
        if(i == m-1 && j==n-1)
        {
            return grid[i][j];
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int right = grid[i][j] + solve(grid , i , j+1);
        int down = grid[i][j] + solve(grid , i+1 , j) ; 

        return t[i][j] = min(right , down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(grid , 0 , 0 );
        
    }
};