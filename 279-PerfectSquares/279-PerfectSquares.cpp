// Last updated: 10/5/2025, 8:59:50 AM
class Solution {
public:
  int arr[100001];
int solve(int n)
{
     if(n==0)
        {
            return 0;
        }
        if(arr[n]!=-1)
        {
            return arr[n];
        }
    int mincount=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int res=1+solve(n-(i*i));
            mincount=min(mincount,res);
        }
        return arr[n]=mincount;
}
    int numSquares(int n) {
        memset(arr,-1,sizeof(arr));
        return solve(n);
 
    }
};