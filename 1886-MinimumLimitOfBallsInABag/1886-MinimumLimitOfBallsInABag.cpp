// Last updated: 10/5/2025, 8:54:06 AM
class Solution {
public:
     bool solve(vector<int>& nums, int maxOperations , int mid)
     {
        int op  = 0 ; 
        for(auto ele : nums)
        {
            if(ele>mid)
            {
               op += ceil((double)ele / mid) - 1;

            }
            if(op>maxOperations)
            {
                return false ;
            }
        }
        return true;

     }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1 ; 
        int ans = 0 ;
        int high = *max_element(begin(nums) , end(nums)) ; 
        while(low<=high)
        {
            int mid = low+(high-low)/2 ;   //possible ans to devide ; 
            if(solve(nums , maxOperations , mid))
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