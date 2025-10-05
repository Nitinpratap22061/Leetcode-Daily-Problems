// Last updated: 10/5/2025, 9:00:15 AM
class Solution {
public:
    int m ; 
    int n;
    int t[301][301];
    int solve(int i , int j , vector<vector<char>>& matrix)
    {
        if(i>=m || j>=n)
        {
            return 0 ; 
        }
        if(matrix[i][j]=='0')
        {
            return 0;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int right = solve(i,j+1,matrix);
        int below = solve(i+1,j,matrix);
        int diagonal=solve(i+1,j+1,matrix);

        return t[i][j]=1+min({right,below,diagonal});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int res = 0 ;
        memset(t,-1,sizeof(t));
        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n ; j++)
            {
                if(matrix[i][j]=='1')
                {
                    res=max(res,solve(i,j,matrix));

                }
            }
        }
        return res*res;
        
    }
};