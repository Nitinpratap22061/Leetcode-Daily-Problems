// Last updated: 10/5/2025, 8:49:34 AM
class Solution {
public:
  int m , n ;
    bool isSafe(int i , int j)
{
    return (i >= 0 && i < m && j >= 0 && j < n);
}

     vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}};
     typedef pair<int,pair<int,int>>P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
         m = moveTime.size();
         n = moveTime[0].size();
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>result(m , vector<int>(n,INT_MAX));
        pq.push({0 , {0,0}});
        result[0][0] = 0 ;
        //khandani dijkstra
        while(!pq.empty())
        {
            int currTime = pq.top().first ; 
            int i = pq.top().second.first;
            int j = pq.top().second.second ;
            pq.pop(); 
            //iss i j se kahan kahan jaa skte
            for(auto &dir : directions)
            {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(isSafe(new_i , new_j))
                {
                    int wait = max(0, moveTime[new_i][new_j] - currTime);
                    int finalTime = wait+currTime+1 ; 
                    if(result[new_i][new_j]>finalTime)
                    {
                        result[new_i][new_j] = finalTime ; 
                        pq.push({finalTime , {new_i , new_j}});
                    }
                }
            }
        }

         return result[m-1][n-1]==INT_MAX?-1:result[m-1][n-1];

    }
};