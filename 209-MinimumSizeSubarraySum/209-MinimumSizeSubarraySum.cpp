// Last updated: 10/5/2025, 9:00:22 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ; 
        int i = 0 ; 
        int j = 0 ;
        int sum  = 0 ; 
        int ans = INT_MAX ; 
        while(j<n)
        {
            sum+=nums[j] ; 
            if(sum>=target)
            {
                while(sum>=target)
                {
                    int ws = j-i+1 ; 
                    ans = min(ans,ws) ; 
                    sum-=nums[i] ; 
                    i++;
                }
            }
            j++ ; 

        }
        return ans==INT_MAX?0:ans ; 
        
    }
};