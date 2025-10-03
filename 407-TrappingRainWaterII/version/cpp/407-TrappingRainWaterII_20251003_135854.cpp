// Last updated: 10/3/2025, 1:58:54 PM
class Solution {
public:
    typedef pair<int,pair<int,int>>P ; 
    vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}} ; 
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size() ; 
        int n = heightMap[0].size() ; 
        priority_queue<P , vector<P> , greater<>> pq ; //{ht , {i,j}} ; 
        vector<vector<bool>>visited(m , vector<bool>(n,false)) ; 

        //boundary celll ko heap me dalao 
        for(int row = 0 ; row<m ; row++)
        {
            for(int col : {0,n-1})
            {
                pq.push({heightMap[row][col] , {row,col}}) ; 
                visited[row][col] = true ; 
            }
        }

        for(int col = 0 ; col<n ; col++)
        {
            for(int row :{0,m-1})
            {
                 pq.push({heightMap[row][col] , {row,col}}) ; 
                  visited[row][col] = true ; 

            }
        }

        //neightbour visit 
        int water = 0 ; 
        while(!pq.empty())
        {
            auto ele = pq.top() ; 
            pq.pop() ; 

            int height = ele.first ; 
            int i = ele.second.first ; 
            int j = ele.second.second ; 

            for(auto &dir:directions)
            {
                int i_ = i+dir[0] ; 
                int j_ = j+dir[1] ; 

                if(i_>=0 && j_>=0 && i_<m && j_<n && !visited[i_][j_])
                {
                    water += max(height - heightMap[i_][j_] , 0) ; 

                    
                    pq.push({max(height , heightMap[i_][j_]) , {i_,j_}}) ; 

                    visited[i_][j_] = true ; 
                }


            }
        }

           return water ; 
        
    }
};