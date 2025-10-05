// Last updated: 10/5/2025, 9:02:26 AM
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ; 
        int l = 0 ; 
        int r = n-1 ; 
        int lmax = 0 ;
        int ans = 0 ;
        int rmax = 0 ;
        while(l<r)
        {
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]) ; 

            if(lmax<rmax)
            {
                ans+=lmax-height[l] ; 
                l++;
            }
            else
            {
                ans+=rmax - height[r] ; 
                r--;
            }
        }
        return ans ; 
         
        
    }
};