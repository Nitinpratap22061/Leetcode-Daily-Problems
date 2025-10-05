// Last updated: 10/5/2025, 8:57:00 AM
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int,int>>& visited) {
        visited.insert({i, j});
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if ((new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) &&
                (grid[new_i][new_j] == 1) &&
                visited.find({new_i, new_j}) == visited.end()) {
                dfs(grid, new_i, new_j, visited);
            }
        }
    }

    int bfs(vector<vector<int>>& grid, const set<pair<int,int>>& originalVisited) {
        queue<pair<int,int>> q;
        set<pair<int,int>> visited = originalVisited;  

        for (auto &it : originalVisited) {
            q.push(it);
        }

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front(); q.pop();
                int x = p.first;
                int y = p.second;
                for (auto &dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
                        visited.find({new_x, new_y}) == visited.end()) {

                        if (grid[new_x][new_y] == 1) {
                            return level;
                        }

                        visited.insert({new_x, new_y});
                        q.push({new_x, new_y});
                    }
                }
            }
            level++;
        }

        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        set<pair<int,int>> visited;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visited);     
                    return bfs(grid, visited);    
                }
            }
        }

        return -1;
    }
};
