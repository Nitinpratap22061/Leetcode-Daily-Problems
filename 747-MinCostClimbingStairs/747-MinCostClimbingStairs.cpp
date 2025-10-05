// Last updated: 10/5/2025, 8:57:54 AM
class Solution {
public:
   int t[1001];
    int solve(vector<int>& cost , int n)
    {
        if(n==0||n==1)
        {
           return 0 ;
        }
        if(t[n]!=-1)
        {
            return t[n];
        }
        int onestep = cost[n-1]+solve(cost,n-1);
        int twostep = cost[n-2]+solve(cost,n-2);

        return t[n] = min(onestep,twostep);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t,-1,sizeof(t));
        return solve(cost,n);

        
    }
};