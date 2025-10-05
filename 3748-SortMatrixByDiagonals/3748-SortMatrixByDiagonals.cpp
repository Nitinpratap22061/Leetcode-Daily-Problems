// Last updated: 10/5/2025, 8:49:06 AM
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size() ; 
        int m = grid[0].size() ; 

        unordered_map<int,vector<int>>mp ; 

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                int diag = i-j;
                mp[diag].push_back(grid[i][j]) ; 
            }
        }

        for(auto &ele : mp)
        {
            if(ele.first >=0)
            {
                sort(begin(ele.second) , end(ele.second)) ; 
            }
            else
            {
                sort(rbegin(ele.second) , rend(ele.second)) ; 
            }
        }

        //again value pushing to grid 

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                int diag = i-j ; 
                grid[i][j] = mp[diag].back() ;
                mp[diag].pop_back() ; 
            }
        }
        

        return grid ; 
    }
};