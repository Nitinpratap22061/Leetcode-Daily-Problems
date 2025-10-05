// Last updated: 10/5/2025, 8:55:47 AM
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, int> mpRow;
        unordered_map<int, int> mpCol;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mpRow[i]++;
                    mpCol[j]++;
                }
            }
        }
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (mpRow[i] > 1 || mpCol[j] > 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};