// Last updated: 10/5/2025, 8:49:15 AM
class Solution {
public:
         int n , m ; 
         vector<vector<int>>directions = {{1,1} , {1,-1} , {-1,-1} , {-1,1}} ; 
    int solve(int i , int j , int d , bool canTurn , vector<vector<int>>&grid , int val)
    {
        int new_i = i+directions[d][0] ; 
        int new_j = j+directions[d][1] ; 

        if(new_i<0 || new_i>=n || new_j<0 || new_j>=m || grid[new_i][new_j]!=val)
        {
            return 0 ; 
        }
        int length = 0 ; 
        int keepmoving = 1+solve(new_i , new_j , d , canTurn , grid , val==2?0:2) ; 
        length = max(length , keepmoving) ; 
        if(canTurn==true)
        {
           int turn = 1+ solve(new_i , new_j , (d+1)%4 , false , grid , val==2?0:2) ; 
           length = max(length , turn) ; 
        }
           return length ; 
     }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
         n = grid.size() ; 
         m = grid[0].size() ; 
         int res  = 0; 
   

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j]==1)
                {
                    for(int d = 0 ; d<4 ; d++)
                    {
                    bool canTurn = true ; 
                     res = max(res , solve(i , j , d , canTurn , grid , 2)+1) ; 
                    }

                }
            }
        }
        return res ; 
    }
};