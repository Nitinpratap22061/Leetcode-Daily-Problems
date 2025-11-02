// Last updated: 11/3/2025, 1:42:21 AM
class Solution {
public:

    
    void solve(vector<vector<int>>& grid, int i, int j, int m, int n, int di, int dj) {
        int new_i = i + di;
        int new_j = j + dj;

        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) return;
        if (grid[new_i][new_j] == 1 || grid[new_i][new_j] == 2) return;

       
        if (grid[new_i][new_j] == 0) grid[new_i][new_j] = 4;

      
        solve(grid, new_i, new_j, m, n, di, dj);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0-empty, 1-guard, 2-wall, 4-guarded

        // place guards
        for (auto &g : guards)
            grid[g[0]][g[1]] = 1;

        // place walls
        for (auto &w : walls)
            grid[w[0]][w[1]] = 2;

       
        for (auto &g : guards) {
            int i = g[0], j = g[1];
            solve(grid, i, j, m, n, 1, 0);   
            solve(grid, i, j, m, n, -1, 0);  
            solve(grid, i, j, m, n, 0, 1);   
            solve(grid, i, j, m, n, 0, -1); 
        }

        // count unguarded empty cells
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    count++;

        return count;
    }
};
