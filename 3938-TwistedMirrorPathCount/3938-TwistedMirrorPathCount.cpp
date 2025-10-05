// Last updated: 10/5/2025, 8:48:28 AM
class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    int t[501][501] ; 

    int solve(vector<vector<int>>& grid, int i, int j) {
        if(i >= m || j >= n)
        {
            return 0;   
        }
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        if(t[i][j] != -1)
        {
            return t[i][j];
        }

        int paths = 0;

        
        int ni = i, nj = j + 1;
        int dir = 0;
        while(ni < m && nj < n && grid[ni][nj] == 1) {
            if(dir == 0) {
                ni += 1; dir = 1;
            } 
            else {
                nj += 1; dir = 0; 
            }         
        }
        if(ni < m && nj < n)
        {
            paths = (paths + solve(grid, ni, nj)) % MOD;
        }

       
        ni = i + 1; nj = j;
        dir = 1;
        while(ni < m && nj < n && grid[ni][nj] == 1) {
            if(dir == 0) { 
                ni += 1; dir = 1;
            } 
            else {
                nj += 1; dir = 0; 
            }         
        }
        if(ni < m && nj < n) paths = (paths + solve(grid, ni, nj)) % MOD;

        return t[i][j] = paths;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        

      memset(t,-1,sizeof(t)) ; 

        return solve(grid, 0, 0);
    }
};
