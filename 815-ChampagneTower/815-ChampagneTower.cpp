// Last updated: 10/5/2025, 8:57:42 AM
class Solution {
public:
     double t[101][101];
     double solve(int poured , int i , int j)
     {
        if(i<0||j<0||i<j)
        {
            return 0.0;
        }
        if(i==0 && j==0)
        {
            return poured;
        }
        if(t[i][j]!=-1.0)
        {
            return t[i][j];
        }
        double leftup = ((solve(poured,i-1,j-1))-1.0)/2.0;
        if (leftup<0) leftup=0.0;
        double rightup = ((solve(poured,i-1,j))-1.0)/2.0;
        if (rightup<0) rightup = 0.0;

        return t[i][j]=leftup+rightup;

     }
    double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                t[i][j] = -1.0;
        return min(1.0,solve(poured,query_row,query_glass));
        
    }
};