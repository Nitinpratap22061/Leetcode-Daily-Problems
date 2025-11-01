// Last updated: 11/1/2025, 7:19:41 PM
class Solution {
public:

    int m , n ; 
    bool checkKyaIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int i , int j)
    {
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size())
        {
            return true ; 
        }
        if(grid2[i][j]==0 || grid2[i][j]==-1)  
        {
            return true ; 
        }

        grid2[i][j] = -1 ; 

        bool res= (grid1[i][j]==1) ; 

        res = res&checkKyaIsland(grid1 , grid2 , i+1 , j) ; 
        res = res&checkKyaIsland(grid1 , grid2 , i-1 , j) ; 
        res = res&checkKyaIsland(grid1 , grid2 , i , j-1) ; 
        res = res&checkKyaIsland(grid1 , grid2 , i , j+1) ; 

        return res ; 



    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        m = grid2.size() ; 
        n = grid2[0].size() ; 
        int res = 0 ; 

        for(int  i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid2[i][j]==1 &&checkKyaIsland(grid1 , grid2 , i , j))
                {
                       res++ ; 
                }
            }
        } 

        return res ; 
        
    }
};