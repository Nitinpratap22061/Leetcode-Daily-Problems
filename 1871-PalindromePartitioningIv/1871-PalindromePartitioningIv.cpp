// Last updated: 10/5/2025, 8:54:12 AM
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));

        // Fill isPalindrome DP table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (i == j) {
                    isPalin[i][j] = true;
                } else if (s[i] == s[j]) {
                    if (j - i == 1) isPalin[i][j] = true;
                    else isPalin[i][j] = isPalin[i + 1][j - 1];
                }
            }
        }

        // Try all i and j to make 3 parts
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPalin[0][i - 1] && isPalin[i][j - 1] && isPalin[j][n - 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};
