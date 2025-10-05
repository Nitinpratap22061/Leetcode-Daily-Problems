// Last updated: 10/5/2025, 8:53:30 AM
class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, m;

    void dfs(int i, int j, vector<vector<int>>& land, vector<vector<bool>>& visited, int& r2, int& c2) {
        visited[i][j] = true;
        r2 = max(r2, i);
        c2 = max(c2, j);

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                land[ni][nj] == 1 && !visited[ni][nj]) {
                dfs(ni, nj, land, visited, r2, c2);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> result;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (land[i][j] == 1 && !visited[i][j]) {
                    int r1 = i, c1 = j;
                    int r2 = i, c2 = j;
                    dfs(i, j, land, visited, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }

        return result;
    }
};
