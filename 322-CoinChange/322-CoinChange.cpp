// Last updated: 10/5/2025, 8:59:39 AM
class Solution {
public:
int t[13][100001];
int solve(vector<int>&coins,int amount,int idx)
{
    int take,skip;
    take=INT_MAX;
    if(amount==0)
    {
        return 0;
    }
    if(idx==coins.size())
    {
        return INT_MAX;
    }
    if(t[idx][amount]!=-1)
    {
        return t[idx][amount];
    }
    if(coins[idx]>amount)
    {
        return t[idx][amount]=solve(coins,amount,idx+1);
    }
    if(coins[idx]<=amount)
    {
    int takeres=solve(coins,amount-coins[idx],idx);
     if(takeres!=INT_MAX)
     {
         take=1+takeres;
     }
    }
     skip=solve(coins,amount,idx+1);
    return t[idx][amount] =min(take,skip);


}
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int result= solve(coins,amount,0);
        return result == INT_MAX ? -1 : result;


        
    }
};