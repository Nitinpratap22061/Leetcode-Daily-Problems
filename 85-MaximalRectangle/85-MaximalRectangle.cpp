// Last updated: 10/5/2025, 9:01:49 AM
class Solution {
public:
    int m, n;

    int solve(vector<vector<char>>& matrix, int i, int j) {
        if (i >= m || j >= n || matrix[i][j] == '0')
            return 0;

        int minWidth = INT_MAX;
        int maxArea = 0;

        for (int row = i; row < m && matrix[row][j] == '1'; row++) {
            int width = 0;
            int col = j;
            while (col < n && matrix[row][col] == '1') {
                width++;
                col++;
            }
            minWidth = min(minWidth, width);
            int height = row - i + 1;
            maxArea = max(maxArea, minWidth * height);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    int ans = solve(matrix, i, j);
                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }
};
