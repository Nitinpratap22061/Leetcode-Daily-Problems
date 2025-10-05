// Last updated: 10/5/2025, 8:55:48 AM
class Solution {
public:
    int n;
    int t[1001][2001];
    int solve(vector<vector<int>>& piles , int i , int coins)
    {
        if(i>=n) return 0 ;

        if(t[i][coins]!=-1)
        {
            return t[i][coins];
        }

        int notTaken = solve(piles , i+1 , coins);

        //take 
        int sum = 0 ;
        int maxres = 0;
        for(int j = 0 ; j<min((int)piles[i].size() , coins) ; j++)
        {
            sum+=piles[i][j] ; 
            int money = sum+solve(piles,i+1,(coins-(j+1)));
            maxres = max(maxres , money);

        }
        return t[i][coins] = max(maxres , notTaken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size() ;
        memset(t,-1,sizeof(t));
        return solve(piles , 0 , k);
        

        
    }
};