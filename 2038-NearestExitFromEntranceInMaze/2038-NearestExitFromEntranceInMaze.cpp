// Last updated: 10/5/2025, 8:53:41 AM
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int col = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                pair<int, int> temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;

                if (temp != make_pair(entrance[0], entrance[1]) && 
                    (i == 0 || i == rows - 1 || j == 0 || j == col - 1)) {
                    return steps;
                }

                // Explore the directions up, down, left, & right
                for (auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < col && maze[new_i][new_j] != '+') {
                        q.push({new_i, new_j});
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
