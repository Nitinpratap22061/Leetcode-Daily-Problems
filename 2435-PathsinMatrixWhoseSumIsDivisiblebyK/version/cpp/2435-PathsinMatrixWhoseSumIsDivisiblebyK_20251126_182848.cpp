// Last updated: 11/26/2025, 6:28:48 PM
1class Solution {
2public:
3       int m ; 
4       int n ; 
5
6        const int MOD = 1e9+7 ; 
7
8        vector<vector<vector<int>>>dp  ; 
9      
10       int solve(int i , int j , vector<vector<int>>& grid, int k , int sum) 
11       {
12
13         if (i >= m || j >= n) return 0;
14
15         if(dp[i][j][sum]!=-1)
16         {
17            return dp[i][j][sum] ; 
18         }
19         if(i==m-1 && j==n-1)
20         {
21            //ek sahi paath mil skta hai 
22
23            sum+=grid[i][j] ; 
24            sum = sum%k ; 
25
26            if(sum==0)
27            {
28                return 1 ; 
29            }
30            else
31            {
32                return 0 ; 
33            }
34
35         }
36
37         //do option
38
39          int one = solve(i+1 , j , grid , k , (sum+grid[i][j])%k) ; 
40         int second = solve(i , j+1 , grid , k , (sum+grid[i][j])%k) ;
41
42         return dp[i][j][sum] = (one+second)%MOD ; 
43
44
45       }
46    int numberOfPaths(vector<vector<int>>& grid, int k) {
47
48        m = grid.size() ; 
49        n = grid[0].size() ; 
50
51     dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
52
53        return solve(0 , 0 , grid , k , 0) ; 
54
55
56        
57    }
58};