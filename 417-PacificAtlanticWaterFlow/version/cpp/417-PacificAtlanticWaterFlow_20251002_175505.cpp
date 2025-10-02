// Last updated: 10/2/2025, 5:55:05 PM
class Solution {
public:
         int m , n ; 
       vector<vector<int>>directions = {{0,1} , {1,0} , {-1,0} , {0,-1}} ; 
    set<pair<int,int>>bfs(vector<vector<int>>& heights , set<pair<int,int>> helper)
    {          //multi source bfs 
             queue<pair<int,int>>q ; 
             for(auto &cell : helper)
             {
                q.push(cell) ; 
             }

             while(!q.empty())
             {
                auto ele = q.front() ; 
                q.pop() ; 
                int row = ele.first ; 
                int col = ele.second ; 

                for(auto &dir : directions)
                {
                    int new_row = row+dir[0] ;
                    int new_col = col+dir[1] ; 

                    if(new_row <0 || new_col <0 || new_row>=m || new_col>=n)
                    {
                        continue ; 
                    }

                    //bada height dhundhna since whan se flow hua so if height more than flow 
                    if(heights[new_row][new_col]>=heights[row][col] && !helper.count({new_row , new_col}))
                    {
                        helper.insert({new_row , new_col}) ; 
                        q.push({new_row , new_col}) ; 
                    }
                }
             }

             return helper ; 

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         m = heights.size() ; 
         n  = heights[0].size() ; 

        set<pair<int,int>>pacific ; 
        set<pair<int,int>>atlantic ; 

        for(int row =0 ; row<m ; row++)
        {
              pacific.insert({row , 0}) ; 
        }
        for(int col =0 ; col<n ; col++)
        {
              pacific.insert({0 , col}) ; 
        }
        //atlantic 
         for(int row =0 ; row<m ; row++)
        {
           
              atlantic.insert({row , n-1}) ; 
        }
         for(int col =0 ; col<n ; col++)
        {
              atlantic.insert({m-1 , col}) ; 
        }

       auto pacifics =  bfs(heights , pacific) ; 
        auto atlantics = bfs (heights , atlantic) ; 

        vector<vector<int>>res ; 
        for(auto &cell : pacifics)
        {
            if(atlantics.count(cell))
            {
                res.push_back({cell.first , cell.second}) ; 
            }
        }
        return res ; 


        
        
    }
};