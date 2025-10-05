// Last updated: 10/5/2025, 8:53:17 AM
class Solution {
public:
    bool solve(int n, vector<int>& quantities , int mid) 
    {
        for(auto product : quantities)
        {
            n-=ceil((double)product/mid) ; 
            if(n<0)
            {
                return false ; 
            }
        }
        return true ; 

    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1 ; 
        int high = *max_element(begin(quantities) , end(quantities)) ; 
        int ans = 0 ; 
        while(low<=high)
        {
            int mid = low+(high-low)/2 ; 
            if(solve(n , quantities , mid))
            {
               ans = mid ; 
               high = mid-1 ; 
            }
            else
            {
                low = mid+1 ; 
            }
        }
        return ans ; 

        
    }
};