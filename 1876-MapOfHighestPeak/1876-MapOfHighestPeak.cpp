// Last updated: 10/5/2025, 8:54:11 AM
class Solution {
public:
 vector<vector<int>>directions={{0,-1} , {0,1} , {-1,0} , {1,0}};
 typedef pair<int,int>P;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size() ; 
        int n = isWater[0].size();
        queue<P>q;
        vector<vector<int>> height(m, vector<int>(n, -1));
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(isWater[i][j]==1)
                {
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int level = 0 ;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto curr = q.front();
                q.pop();
                int i  = curr.first;
                int j = curr.second;
                for(auto &dir:directions)
                {
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];
                    if(new_i >=0 && new_j>=0 && new_i<m && new_j<n && height[new_i][new_j]==-1)
                    {
                          height[new_i][new_j] = height[i][j]+1;
                          q.push({new_i , new_j});
                    }
                }
            }
            level++;
        }
       return height;
       
        
    }
};