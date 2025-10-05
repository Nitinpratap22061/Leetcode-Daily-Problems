// Last updated: 10/5/2025, 9:02:09 AM
class Solution {
public:
int t[101][101];
     int solve( vector<vector<int>>& obstacleGrid , int i , int j)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(i>=m || j>=n || obstacleGrid[i][j]==1)
        {
          return 0;
        }
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int right = solve(obstacleGrid,i,j+1);
        int down = solve(obstacleGrid,i+1,j);
        return t[i][j] = right + down ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(t,-1,sizeof(t));
        return solve(obstacleGrid ,0 , 0);
        

    }
};