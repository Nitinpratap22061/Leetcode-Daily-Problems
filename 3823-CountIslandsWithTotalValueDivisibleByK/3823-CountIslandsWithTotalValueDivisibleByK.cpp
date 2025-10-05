// Last updated: 10/5/2025, 8:48:52 AM
class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j ,vector<vector<bool>>& visited ) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;
        long long sum = grid[i][j];

       
        sum += solve(grid, i + 1, j , visited);
        sum += solve(grid, i - 1, j , visited);
        sum += solve(grid, i, j + 1 , visited);
        sum += solve(grid, i, j - 1 , visited);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    int total = solve(grid, i, j , visited);
                    if (total % k == 0) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
