// Last updated: 10/5/2025, 8:54:47 AM
class Solution {
public:
    int n;
    int t[101][201] ;
    const int MOD =1e9+7;
    int solve(vector<int>& locations, int start, int finish, int fuel)
    {
        if(fuel<0) return 0 ;
        int ans = 0;
        if(start==finish)
        {
           ans+=1 ;
        }
        if(t[start][fuel]!=-1)
        {
            return t[start][fuel] ;
        }
        //explore
        for(int j = 0 ; j<n ; j++)
        {
            if(start!=j)
            {
                int remaining_fuel = fuel - abs(locations[start] - locations[j]);
                ans = (ans + solve(locations , j , finish , remaining_fuel)) % MOD;
            }
        }
        return t[start][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size() ;
        memset(t,-1,sizeof(t));
        return solve(locations , start , finish , fuel);
    }
};