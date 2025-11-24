// Last updated: 11/24/2025, 7:39:25 PM
class Solution {
public:

    int n ; 
     int t[400001][4] ;  
    int solve(int i , int rem , vector<int>& nums)
    {

      if(i>=n)
      {
         if(rem==0)
         {
            return 0 ; 
         }
         else
         {
            return -1e9 ;  
         }
      }  

       if(t[i][rem]!=-1)
       {
        return t[i][rem] ; 
       }

        int take = nums[i]+solve(i+1 , (rem+nums[i])%3 , nums) ; 
        int skip = solve(i+1 , rem , nums) ; 

        return t[i][rem] = max({take , skip}) ; 
    }
    int maxSumDivThree(vector<int>& nums) 
    {

        n = nums.size() ; 
        memset(t,-1,sizeof(t)) ; 
        return solve(0 , 0 , nums) ; 
        
    }
};