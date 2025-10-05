// Last updated: 10/5/2025, 9:00:42 AM
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
            //fill via recursn logic only 
        for(int i = m-1 ; i>=0 ; i--)
        {
            for(int j = n-1 ; j>=0 ; j--)
            {
                if(i==m-1 && j==n-1)
                {
                   if(dungeon[i][j]>0)
                   {
                    dp[i][j]=1;
                   }
                   else
                   {
                    dp[i][j] = abs(dungeon[i][j])+1;
                   }
                }
                else //generic case fill
                {
                    int right = j+1>=n?1e9:dp[i][j+1];
                    int down = i+1>=m?1e9:dp[i+1][j];

                    int res  =  min(right,down) - dungeon[i][j];
                    dp[i][j] = res>0?res:1;

                }
            }
        }
        return dp[0][0];
        
    }
};