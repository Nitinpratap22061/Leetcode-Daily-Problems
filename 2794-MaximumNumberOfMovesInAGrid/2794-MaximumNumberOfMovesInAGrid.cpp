// Last updated: 10/5/2025, 8:51:19 AM
class Solution {
public:
  vector<vector<int>>t;
  int m , n;
     vector<int>directions={-1 , 0 , 1};
    int solve(int row , int col , vector<vector<int>>& grid)
    {

         int moves = 0 ;
         if(t[row][col]!=-1)
         {
            return t[row][col];
         }
        for(auto &dir : directions)
        {
            int new_row = row+dir;
            int new_col = col+1;
            if(new_row >=0 && new_row<m &&new_col>=0 && new_col<n && grid[new_row][new_col] > grid[row][col])
            {
                moves = max(moves , 1+solve(new_row , new_col , grid));

            }
        }
        return t[row][col] = moves;

    }
    int maxMoves(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        int result = 0 ; 
        t.assign(m, vector<int>(n, -1));
        for(int i=0 ; i<m ; i++)
        {
            result = max(result , solve(i , 0 , grid));
        }
        return result;
        
    }
};