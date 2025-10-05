// Last updated: 10/5/2025, 8:51:34 AM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        unordered_map<int,pair<int,int>>map;
        for(int i = 0 ; i<m ; i++ )
        {
            for(int j=0 ; j<grid[0].size();j++)
            {
                int val = grid[i][j];
                map[val] = {i,j};
            }
        }
           vector<int>rowPaintCount(m,0) ; 
           vector<int>colPaintCount(n,0) ; 
        for(int i = 0 ; i<arr.size() ; i++)
        {
            int value = arr[i] ; 
            auto[row,col] = map[value] ; 
            grid[row][col] *=-1; // paint

            rowPaintCount[row]++;
            colPaintCount[col]++;

            if(rowPaintCount[row]==n || colPaintCount[col] ==m)
            {
                return i ;
            }



        }


        return -1;
        
    }
};