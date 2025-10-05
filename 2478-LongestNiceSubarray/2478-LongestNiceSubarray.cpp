// Last updated: 10/5/2025, 8:52:12 AM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size() ;
        int i = 0 ;
        int j = 0 ;
        int mask = 0 ;
        int res = 0 ;
        while(j<n)
        {
            while((mask & nums[j])!=0)  //shrink
            {
                mask = mask ^ nums[i] ; 
                i++ ;
            }
            res = max(res,j-i+1);
            mask = mask | nums[j] ;
            j++;
        }
        return res ;
        
    }
};