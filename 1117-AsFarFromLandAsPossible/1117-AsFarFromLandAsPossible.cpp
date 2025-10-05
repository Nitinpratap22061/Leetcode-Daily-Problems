// Last updated: 10/5/2025, 8:56:30 AM
class Solution {
public:
vector<vector<int>>directions = {{0,1} , {0,-1} , {1,0} , {-1,0}};
typedef pair<int,int>P;
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size();
        queue<P>q;
        int land=0;
        for(int i = 0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    land++;
                }
            }
        }
        if(land==0 || land==m*n) return -1;

        int level = 0 ;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto curr= q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(auto &dir:directions)
                {
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];
                    if(new_i>= 0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]==0)
                    {
                        grid[new_i][new_j]=1;
                        q.push({new_i , new_j});
                    }
                }
            }
            level++;
        }
        return level-1;
    }
};