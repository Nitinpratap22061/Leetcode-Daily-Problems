// Last updated: 10/5/2025, 9:02:00 AM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>>vec ; 
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(matrix[i][j]==0)
                {
                    vec.push_back({i,j});
                }
            }
        }
        for(auto ele:vec)
        {
            int i = ele.first;
            int j = ele.second;
            for(int k = 0 ;k<n;k++)
            {
                matrix[i][k]=0;
            }
            for(int k=0 ; k<m ; k++)
            {
                matrix[k][j]=0;
            }
        }
        return ;
    }
};