// Last updated: 11/14/2025, 10:31:15 PM
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>grid(n,vector<int>(n,0)) ; 

        for(auto ele : queries)
        {
            int i = ele[0] ; 
            int j = ele[1] ; 

            int i_ = ele[2] ; 
            int j_ = ele[3] ; 

            for(int k = i ; k<=i_ ; k++)
            {
                for(int p = j ; p<=j_ ; p++)
                {
                    grid[k][p] = grid[k][p]+1 ; 
                }
            }
        }

        return grid ; 


        
    }
};