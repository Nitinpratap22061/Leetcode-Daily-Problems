// Last updated: 10/5/2025, 9:00:37 AM
class Solution {
public:
int dp[2][100001][101];
int n;
    int solve(vector<int>& prices , bool canBuy , int i , int transaction)
    {
        if(i>=n || transaction==0)
        {
            return 0 ; 
        }
        //buy
        if(dp[canBuy][i][transaction]!=-1)
        {
            return dp[canBuy][i][transaction];
        }
       int profit = 0 ;
        if(canBuy)
        {
           int  buy = -prices[i]+solve(prices,false,i+1,transaction);
           int skip = solve(prices,true , i+1 , transaction);

           profit = max(buy,skip);
        }
        else
        {
            int sell = prices[i]+solve(prices,true,i+1,transaction-1);
            int skip = solve(prices,false , i+1 , transaction);

            profit = max(sell,skip);

        }
        return  dp[canBuy][i][transaction] =  profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n  = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices , true , 0 , k);
        
    }
};