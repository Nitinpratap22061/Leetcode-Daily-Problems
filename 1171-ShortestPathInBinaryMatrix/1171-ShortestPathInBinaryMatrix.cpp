// Last updated: 10/5/2025, 8:56:23 AM
class Solution {
public:
     typedef pair<int , int>P;
      vector<vector<int>>direction={{-1,0} , {1,0} , {0,-1} , {0,1},{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        {
            return -1;
        }
       queue<P>q;
       vector<vector<int>>visited(m,vector<int>(n,-1));
       q.push({0,0});
       visited[0][0] = 1 ;
       int level = 1 ;
       while(!q.empty())
       {
        int size = q.size();
        while(size--)
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if (i == m - 1 && j == n - 1) return level;
            
            for(auto &dir : direction)
            {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]==0 && visited[new_i][new_j]==-1)
                {
                      visited[new_i][new_j] = 1;
                      q.push({new_i , new_j});
                }
            }
        }
        level++;
       }
       return -1;
    }
};