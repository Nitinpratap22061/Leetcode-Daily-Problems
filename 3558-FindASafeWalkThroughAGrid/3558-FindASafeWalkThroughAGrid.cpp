// Last updated: 10/5/2025, 8:49:45 AM
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        if (grid[0][0] == 1) {
            health--;
        }

       
        if (health <= 0) return false;

        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

       
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, health});

       
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = health;

        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int row = current.first.first;
            int col = current.first.second;
            int currHealth = current.second;

           
            if (row == m - 1 && col == n - 1 && currHealth > 0) {
                return true;
            }

            
            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int newHealth = currHealth;

                    
                    if (grid[newRow][newCol] == 1) {
                        newHealth--;
                    }

                    
                    if (newHealth > 0 && (visited[newRow][newCol] == -1 || newHealth > visited[newRow][newCol])) {
                        visited[newRow][newCol] = newHealth;
                        q.push({{newRow, newCol}, newHealth});
                    }
                }
            }
        }

       
        return false;
    }
};
