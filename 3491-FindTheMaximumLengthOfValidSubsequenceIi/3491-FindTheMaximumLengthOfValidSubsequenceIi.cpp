// Last updated: 10/5/2025, 8:49:56 AM
class Solution {
public:
  
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size() ; 
       vector<vector<int>>dp(k,vector<int>(n,1)) ;
       int maxl = 1 ; 
     
       for(int i =1 ; i<n ; i++)
       {
        for(int j = 0 ; j<i ; j++)
        {
            int mod = (nums[i]+nums[j])%k ; 
            dp[mod][i] = max(dp[mod][i] , 1+dp[mod][j]) ; 
            maxl = max(maxl , dp[mod][i]) ; 
        }
       }
       return maxl;
    }
};