// Last updated: 10/5/2025, 8:54:37 AM
class Solution {
public:
         typedef  pair<int,pair<int,int>>P;
         vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size();
       priority_queue<P,vector<P>,greater<P>>pq;
       vector<vector<int>>result(m,vector<int>(n,INT_MAX));
       result[0][0] = 0 ;
       pq.push({0 , {0 , 0}});
       while(!pq.empty())
       {
         auto curr = pq.top();
         pq.pop();
         int d = curr.first ;
         int i = curr.second.first;
         int j = curr.second.second;
         for(auto &dir : direction)
         {
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(new_i>=0 && new_i <m && new_j>=0 && new_j<n)
            {
                int wt = abs(grid[new_i][new_j] - grid[i][j]);
                int maxDiff = max(wt , d);
                if(result[new_i][new_j]>maxDiff)
                {
                    result[new_i][new_j] = maxDiff ;
                    pq.push({maxDiff , {new_i , new_j}});
                }
            }
         }
       }
       return result[m-1][n-1];
    }
};