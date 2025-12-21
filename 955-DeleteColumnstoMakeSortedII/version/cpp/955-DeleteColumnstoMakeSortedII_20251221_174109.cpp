// Last updated: 12/21/2025, 5:41:09 PM
1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int rows = strs.size() ; 
5        int cols = strs[0].size() ; 
6
7        int deletion = 0 ; 
8        vector<bool>alreadySorted(rows , false) ; 
9
10
11        for(int col = 0 ; col<cols ; col++)
12        {
13            bool deleted  = false ; 
14            for(int row = 0 ; row<rows-1 ; row++)
15            {
16                if(!alreadySorted[row] && strs[row][col] >strs[row+1][col])
17                {
18                    deletion++ ; 
19                    deleted = true ; 
20                    break ; 
21
22                }
23
24
25
26            }
27            if(deleted)
28            {
29                continue ; 
30            }
31            for(int i = 0 ; i<rows-1 ; i++)
32            {
33                alreadySorted[i] = alreadySorted[i]|strs[i][col] < strs[i+1][col] ; 
34            }
35        }
36        return deletion ; 
37        
38    }
39};