// Last updated: 10/5/2025, 8:52:32 AM
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size(); 
         while(n>0)
         {
            if(n==1)
            {
                return nums[0] ; 
            }
            vector<int>news(n/2 , 0 );
            for(int i = 0 ; i<n/2 ; i++)
            {
                if(i%2==0) {
                    news[i] = min(nums[2*i] , nums[2*i+1]);
                }
                else
                {
                    news[i] = max(nums[2*i] , nums[2*i+1]);
                }
            }
            nums = news ; 
            n = n/2 ; 
         }

         return nums[0];
        
    }
};