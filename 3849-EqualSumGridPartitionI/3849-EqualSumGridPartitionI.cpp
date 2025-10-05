// Last updated: 10/5/2025, 8:48:49 AM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Calculate total sum
        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }

      
        long long currRowSum = 0;
        for (int i = 0; i < m - 1; i++) { 
            for (int j = 0; j < n; j++) {
                currRowSum += grid[i][j];
            }
            if (currRowSum * 2 == totalSum) {
                return true;
            }
        }

        
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }

        long long currColSum = 0;
        for (int j = 0; j < n - 1; ++j) { 
            currColSum += colSum[j];
            if (currColSum * 2 == totalSum) {
                return true;
            }
        }

        return false;
    }
};
