// Last updated: 1/18/2026, 12:38:21 PM
1class Solution {
2public:
3    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
4        sort(begin(towers) , end(towers)) ; 
5        pair<int,int>mylocn = {center[0] , center[1]} ; 
6        int maxi = INT_MIN ; 
7          vector<int>ans= {-1,-1} ; 
8        for(auto tower : towers)
9        {
10            int u = tower[0] ; 
11            int v = tower[1] ; 
12            int q = tower[2] ; 
13
14            int d = abs(u-mylocn.first)+abs(v-mylocn.second) ; 
15            if(d<=radius)
16            {
17               if(q>maxi)
18               {
19                maxi = q ; 
20                ans = {u,v} ; 
21
22               }
23            }
24
25        }
26
27        return ans ; 
28        
29    }
30};