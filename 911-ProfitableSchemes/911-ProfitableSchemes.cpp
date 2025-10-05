// Last updated: 10/5/2025, 8:57:17 AM
class Solution {
public:
   int N;
   int t[101][101][101];
   const int MOD = 1e9+7;
   int solve(int i , int p , int people , int &minProfit , vector<int>& profit , vector<int>& group)
   {
    if(people>N) return 0 ; 
    if(i==group.size())
    {
        if(p>=minProfit) return 1;
        else return 0 ; 
    }
    if(t[i][p][people]!=-1)
    {
        return t[i][p][people];
    }
    int taken = solve(i+1 , min(p+profit[i] , minProfit) , people+group[i] , minProfit , profit , group)%MOD;
    int not_taken = solve(i+1,p,people,minProfit,profit,group)%MOD;
    return t[i][p][people] =  (taken+not_taken)%MOD;
   }


    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=n;
        memset(t,-1,sizeof(t));
        return solve(0 , 0 , 0 , minProfit , profit , group);
        
    }
};