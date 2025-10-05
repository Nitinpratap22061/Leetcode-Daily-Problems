// Last updated: 10/5/2025, 8:50:33 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diag = 0 ; 
        int area = 0 ; 

        for(auto ele : dimensions)
        {
            int a = ele[0] ; 
            int b = ele[1] ; 
            double currdiag = sqrt(a*a + b*b) ; 
            if(currdiag>diag)
            {
                diag = currdiag ; 
                area = a*b ; 
            }
            else if(currdiag == diag)
            {
                area = max(area,a*b) ; 
            }

        }

        return area ; 
        
    }
};