// Last updated: 10/6/2025, 11:22:18 AM
class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>> vis(m, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int time = t[0], i = t[1], j = t[2];

            if (i == m-1 && j == m-1) return time;

            for (auto &d : directions) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < m && !vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    pq.push({max(time, grid[ni][nj]), ni, nj});
                }
            }
        }

        return -1;
    }
};
