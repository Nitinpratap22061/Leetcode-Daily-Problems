// Last updated: 9/25/2025, 12:24:17 PM
class Solution {
public:
    int n;
    int t[201][2000];
    int solve(vector<vector<int>>& triangle , int i , int j)
    {

       
         if (i >= n || j >= triangle[i].size())
          {
            return 0;
          }

          if(t[i][j]!=-1)
          {
            return t[i][j];
          }



        int first = triangle[i][j]+solve(triangle,i+1,j);
        int second = triangle[i][j]+solve(triangle,i+1,j+1);

        return t[i][j]=min(first,second);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        memset(t,-1,sizeof(t));
        return solve(triangle , 0 , 0);        
    }
};