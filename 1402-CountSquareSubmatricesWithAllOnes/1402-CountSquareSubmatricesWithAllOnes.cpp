// Last updated: 10/5/2025, 8:55:46 AM
class Solution {
public:
    int m;
    int n;
    int result = 0;
    int dp[300][300];

    int solve(int i, int j, vector<vector<int>>& matrix) {
        // Base cases: if out of bounds or if the cell has a zero
        if (i >= m || j >= n || matrix[i][j] == 0) {
            return 0;
        }

        // If the result is already calculated, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recursive calls for right, diagonal, and down cells
        int right = solve(i, j + 1, matrix);
        int diag = solve(i + 1, j + 1, matrix);
        int down = solve(i + 1, j, matrix);

        // Memoize the result
        dp[i][j] = 1 + min({right, diag, down});

        return dp[i][j];
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        result = 0;
        memset(dp, -1, sizeof(dp));  // Initialize dp with -1

        // Traverse through each cell in the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    result += solve(i, j, matrix);  // Add the number of squares ending at (i, j)
                }
            }
        }

        return result;
    }
};
