// Last updated: 1/2/2026, 1:11:24 PM
1class Solution {
2public:
3     int ROW ; 
4     int COL ; 
5    vector<vector<int>>directions = {{1,0} , {-1,0} , {0,1} , {0,-1} } ; 
6    bool DFS(vector<vector<int>>& grid , int i , int j)
7    {
8        if(i<0 || i>=ROW || j<0 || j>=COL || grid[i][j]==1)
9        {
10            return false ; 
11        }
12        if(i==ROW-1)
13        {
14            return true ; 
15        }
16        grid[i][j] = 1 ; 
17
18        for(auto &dir : directions)
19        {
20            int new_i = i+dir[0] ; 
21            int new_j = j+dir[1] ; 
22            if(DFS(grid , new_i , new_j))
23            {
24                return true ; 
25            }
26        }
27        return false ; 
28    }
29    bool canCross(vector<vector<int>>& cells , int mid)
30    {
31        vector<vector<int>>grid(ROW , vector<int>(COL , 0)) ; 
32        for(int i = 0 ; i<=mid ; i++)
33        {
34            int x = cells[i][0]-1 ; 
35            int y = cells[i][1] -1 ; 
36            grid[x][y] = 1 ; 
37        }
38        for(int j = 0 ; j<COL ; j++)
39        {
40              if(grid[0][j]==0 && DFS(grid , 0 , j))
41              {
42                return true ; 
43              }
44        }
45        return false ; 
46    }
47    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
48        ROW = row ; 
49        COL = col ; 
50
51        int l =  0 ; 
52        int r = cells.size() - 1 ; 
53        int last_day = 0 ; 
54
55        while(l<=r)
56        {
57            int mid = l+(r-l)/2 ; 
58
59            if(canCross(cells , mid))
60            {
61                last_day = mid+1 ; 
62                l = mid+1 ; 
63            }
64            else
65            {
66                r = mid-1 ; 
67            }
68
69        }
70        return last_day ; 
71    }
72};