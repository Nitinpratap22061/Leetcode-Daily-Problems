// Last updated: 10/5/2025, 8:53:23 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size() ; 
        int n = grid[0].size() ;
        vector<int>ans ; 
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin() , ans.end()) ;
        int k = ans.size();
        int idx = ceil(k/2);
        int target = ans[idx] ;
        int score = 0 ;
        for(int i = 0 ; i<ans.size() ; i++)
        {
            if((abs(target-ans[i]))%x!=0)
            {
                return -1 ;
            }
            int helper = abs(target-ans[i]);
            int step = helper/x;
            score+=step;
        }
        return score;
    }
};