// Last updated: 10/5/2025, 8:58:48 AM
class Solution {
public:
      int t[305][5002];
    int solve( vector<int>& coins , int index , int amount)
    {
        int n = coins.size() ; 
        if(index>=n) return 0;
        if(amount == 0 ) return 1;
        if(t[index][amount]!=-1)
        {
            return t[index][amount];
        }
        //take
        
        if(coins[index]>amount)
        {
            return solve(coins , index+1 , amount);
        }
        int take = solve(coins , index , amount - coins[index] );
        
        int skip = solve(coins , index+1 , amount);

        return t[index][amount] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(coins , 0 , amount);   
    }
};