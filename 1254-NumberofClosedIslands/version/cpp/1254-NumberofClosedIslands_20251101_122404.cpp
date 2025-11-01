// Last updated: 11/1/2025, 12:24:04 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
       
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (grid[i][j] == 1 || visited[i][j])
            return true;

        visited[i][j] = true;

     
        bool up    = dfs(i - 1, j, grid, visited);
        bool down  = dfs(i + 1, j, grid, visited);
        bool left  = dfs(i, j - 1, grid, visited);
        bool right = dfs(i, j + 1, grid, visited);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfs(i, j, grid, visited))
                        count++;
                }
            }
        }

        return count;
    }
};
