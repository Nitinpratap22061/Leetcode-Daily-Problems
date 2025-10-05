// Last updated: 10/5/2025, 8:55:19 AM
class Solution {
public:
    int t[52][52][102] ; 
    const int MOD = 1e9+7;
    int solve(int idx , int sc , int maxVal , int k , int n , int m)
    {
        if(idx == n)
        {
            if(sc==k)
            {
                return 1 ; 
            }
            else
            {
                return 0;
            }
        }
        if(t[idx][sc][maxVal+1]!=-1)
        {
            return t[idx][sc][maxVal+1];
        }
        //explore
        int res=0;
        for(int i=1 ; i<=m ; i++)
        {
            if(i>maxVal)
            {
                res = (res + solve(idx+1 , sc+1 , i , k , n ,m)) % MOD;
            }
            else
            {
                res=(res+solve(idx+1,sc,maxVal,k,n,m))%MOD;
            }
        }

        return t[idx][sc][maxVal+1] = res;
    }
    int numOfArrays(int n, int m, int k) {
        memset(t,-1,sizeof(t));
        return solve( 0 , 0 , -1 , k , n , m);

        
    }
};