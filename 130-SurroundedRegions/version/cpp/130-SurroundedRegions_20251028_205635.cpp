// Last updated: 10/28/2025, 8:56:35 PM
class Solution {
public:

    vector<vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}}; 

    bool issafe(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board) {
        vis[row][col] = 1; 

        int n = board.size();
        int m = board[0].size();

        for (auto &dir : directions) {
            int new_i = row + dir[0]; 
            int new_j = col + dir[1]; 

            if (issafe(new_i, new_j, n, m) && !vis[new_i][new_j] && board[new_i][new_j] == 'O') {
                dfs(new_i, new_j, vis, board);
            }
        }
    }

    void solve(vector<vector<char>> &board) {
        int n = board.size(); 
        int m = board[0].size(); 

        vector<vector<int>> visited(n, vector<int>(m, 0)); 

        for (int j = 0; j < m; j++) {
          
            if (!visited[0][j] && board[0][j] == 'O') {
                dfs(0, j, visited, board); 
            }
          
            if (!visited[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, visited, board); 
            }
        }

     
        for (int i = 0; i < n; i++) {
           
            if (!visited[i][0] && board[i][0] == 'O') { 
                dfs(i, 0, visited, board); 
            }
          
            if (!visited[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, visited, board); 
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};
