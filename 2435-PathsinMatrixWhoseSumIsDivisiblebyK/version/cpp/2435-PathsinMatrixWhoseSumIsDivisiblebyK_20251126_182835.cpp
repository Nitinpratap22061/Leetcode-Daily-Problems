// Last updated: 11/26/2025, 6:28:35 PM
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
12              sum = sum%k ; 
13
14         if (i >= m || j >= n) return 0;
15
16         if(dp[i][j][sum]!=-1)
17         {
18            return dp[i][j][sum] ; 
19         }
20         if(i==m-1 && j==n-1)
21         {
22            //ek sahi paath mil skta hai 
23
24            sum+=grid[i][j] ; 
25            sum = sum%k ; 
26
27            if(sum==0)
28            {
29                return 1 ; 
30            }
31            else
32            {
33                return 0 ; 
34            }
35
36         }
37
38         //do option
39
40          int one = solve(i+1 , j , grid , k , (sum+grid[i][j])%k) ; 
41         int second = solve(i , j+1 , grid , k , (sum+grid[i][j])%k) ;
42
43         return dp[i][j][sum] = (one+second)%MOD ; 
44
45
46       }
47    int numberOfPaths(vector<vector<int>>& grid, int k) {
48
49        m = grid.size() ; 
50        n = grid[0].size() ; 
51
52     dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
53
54        return solve(0 , 0 , grid , k , 0) ; 
55
56
57        
58    }
59};