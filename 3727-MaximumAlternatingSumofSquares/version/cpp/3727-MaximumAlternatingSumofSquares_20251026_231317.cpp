// Last updated: 10/26/2025, 11:13:17 PM
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
          int n  = nums.size() ; 
        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i]<0)
            {
                nums[i] = nums[i]*-1 ; 
            }

        }
        sort(begin(nums) , end(nums)) ; 

      
        long long sum1= 0 ;
        long long sum2 = 0 ;  
        long long ans = 0 ; 
       
            for(int i = n-1 ; i>=n/2 ; i--)
            {
                sum1+=(nums[i]*nums[i]) ; 

            }
            for(int i = 0 ; i<n/2 ; i++)
            {
                sum2+=(nums[i]*nums[i]) ; 
            }

            ans = sum1-sum2 ; 


        
        return ans ; 
        
    }
};