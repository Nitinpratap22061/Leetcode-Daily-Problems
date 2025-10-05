// Last updated: 10/5/2025, 8:56:41 AM
class Solution {
public:
      vector<vector<int>>directions = {{0,1} , {1,0} , {0,-1} , {-1,0}};
      typedef pair<int,int>P;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<P>q;
        int freshCount = 0 ;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                  freshCount++;
                }
            }
        }
        if(freshCount == 0)
        {
            return 0;
        }

        int level = 0 ;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto curr = q.front();
                q.pop();
                int i = curr.first ; 
                int j = curr.second;
                for(auto &dir:directions)
                {
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];
                    if(new_i>=0 && new_i<m && new_j >=0 && new_j<n && grid[new_i][new_j]==1)
                    {
                        grid[new_i][new_j]=2;
                        q.push({new_i , new_j});
                        freshCount--;
                    }
                }
            }
            level++;
        }
        if(freshCount <= 0 )
        {
            return level-1;
        }
        return -1;

        
    }
};