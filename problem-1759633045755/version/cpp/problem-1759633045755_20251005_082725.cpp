// Last updated: 10/5/2025, 8:27:25 AM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int xors = 0 ;
        int n = nums.size() ; 
        int count = 0 ; 
        for(int i = 0 ; i<n ; i++)
            {
                if(nums[i]==0)
                {
                   count++ ; 
                }
                
            }
        if(count == n )
        {
            return  0 ; 
        }
        for(int i = 0 ; i<nums.size() ; i++)
            {
                xors = xors^nums[i] ; 
            }
        if(xors!=0)
        {
            return n ; 
        }
        

       return n-1 ; 
        

        
    }
};
