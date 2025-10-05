// Last updated: 10/5/2025, 8:48:23 AM
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {

        int n = weight.size() ; 
        int maxi = 0 ; 
        int cnt = 0 ; 

        for(int i  = 0 ; i<=n-1 ; i++)
        {
            if(weight[i]>maxi)
            {
                maxi = weight[i] ; 
            }
            else
            {
                if(weight[i]<maxi)
                {
                    cnt++; 
                    maxi = 0 ; 
                }
            
            }
        }

        return cnt ; 
        
    }
};