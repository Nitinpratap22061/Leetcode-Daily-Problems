// Last updated: 10/5/2025, 9:00:03 AM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        // int m = matrix[0].size();
        int row = 0, col = matrix[0].size()-1;
        while(row <n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
                // break;
            }
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};
