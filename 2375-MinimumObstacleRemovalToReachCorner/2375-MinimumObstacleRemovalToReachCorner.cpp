// Last updated: 10/5/2025, 8:52:36 AM
class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> P ;
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for (auto dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    int cost = (grid[new_i][new_j]) == 1 ? 1 : 0;
                    if (cost + d < result[new_i][new_j]) {
                        result[new_i][new_j] = cost + d;
                        pq.push({cost + d, {new_i, new_j}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};