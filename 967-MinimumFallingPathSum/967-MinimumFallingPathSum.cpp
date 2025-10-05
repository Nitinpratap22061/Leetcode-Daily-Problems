// Last updated: 10/5/2025, 8:57:01 AM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        // Initialize the first row
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Build the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i - 1][j];
                int upLeft = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int upRight = (j < m - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({up, upLeft, upRight});
            }
        }

        // Return min from the last row
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
