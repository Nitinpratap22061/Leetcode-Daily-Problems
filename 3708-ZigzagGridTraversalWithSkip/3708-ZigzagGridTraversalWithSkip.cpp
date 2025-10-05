// Last updated: 10/5/2025, 8:49:19 AM
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans;
        int count=0;
        for(int i=0 ; i<m ; i++)
        {
            if(i%2 == 0)
            {
                for(int j=0 ; j<n ; j++)
                {
                    if(j%2==0)
                    {
                        ans.push_back(grid[i][j]);
                    }

                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(j%2!=0)
                    {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
        }
        return ans;
        
    }
};