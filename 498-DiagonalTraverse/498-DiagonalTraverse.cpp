// Last updated: 10/5/2025, 8:58:53 AM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int n = mat.size() ; 
        int m = mat[0].size() ; 

        vector<int>ans ; 

        map<int,vector<int>>mp ; 

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                mp[i+j].push_back(mat[i][j]) ; 
            }
        }

        bool flip = true ; 

        for(auto &ele : mp)
        {
            if(flip)
            {
                reverse(ele.second.begin() , ele.second.end()) ; 
            }
            for(auto &num : ele.second)
            {
                ans.push_back(num) ; 
            }
            flip = !flip ; 
        }
        return ans ; 
    }
};