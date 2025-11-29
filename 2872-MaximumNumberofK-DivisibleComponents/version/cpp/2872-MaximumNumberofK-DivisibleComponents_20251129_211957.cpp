// Last updated: 11/29/2025, 9:19:57 PM
1class Solution {
2public: 
3
4    int count ; 
5
6    int dfs(int curr , int parent ,  unordered_map<int,vector<int>>&mp, vector<int>& values, int k )
7    {
8
9
10        int sum = values[curr] ;
11        for(auto &ngbr : mp[curr])
12        {
13            if(ngbr!=parent)
14            {
15                sum+=dfs(ngbr , curr , mp , values , k) ; 
16
17            }
18        }
19        sum=sum%k ; 
20        if(sum==0)
21        {
22            count++ ; 
23        }
24        return sum ; 
25    }
26    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k ) {
27        
28        //graph bano 
29        unordered_map<int,vector<int>>mp ; 
30        for(auto &edge : edges)
31        {
32            int u = edge[0] ; 
33            int v = edge[1] ; 
34
35            mp[u].push_back(v) ; 
36            mp[v].push_back(u) ; 
37        }
38           count = 0 ; 
39         dfs(0 , -1 , mp , values , k)  ; 
40         return count ; 
41        
42    }
43};