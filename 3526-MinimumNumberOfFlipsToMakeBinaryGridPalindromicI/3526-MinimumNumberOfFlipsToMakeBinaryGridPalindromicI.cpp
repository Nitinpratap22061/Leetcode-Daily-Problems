// Last updated: 10/5/2025, 8:49:49 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        auto minFlipsToPalindrome = [](const vector<int>& line) {
            int flips = 0;
            int length = line.size();
            for (int i = 0; i < length / 2; ++i) {
                if (line[i] != line[length - 1 - i]) {
                    flips++;
                }
            }
            return flips;
        };

        // Calculate flips needed to make all rows palindromic
        int rowFlips = 0;
        for (const auto& row : grid) {
            rowFlips += minFlipsToPalindrome(row);
        }

        // Calculate flips needed to make all columns palindromic
        int colFlips = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> col(m);
            for (int i = 0; i < m; ++i) {
                col[i] = grid[i][j];
            }
            colFlips += minFlipsToPalindrome(col);
        }

        return min(rowFlips, colFlips);
    }
};
