// Last updated: 11/1/2025, 12:16:52 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return false; 
        }
        if (grid[i][j] == 1)
        {
            return true; 
        }
        if (visited[i][j])
            return true; 

        visited[i][j] = true;
        bool isClosed = true;

        for (auto &dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            if (!dfs(ni, nj, grid, visited))
                isClosed = false;
        }

        return isClosed;
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
