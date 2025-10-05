// Last updated: 10/5/2025, 9:00:33 AM
class Solution {
public:
int solve(vector<int>& nums , int i ,  int n, vector<int>&dp)
{
    if(i>n-1)//oub
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    //rob
    int rob = nums[i]+solve(nums,i+2,n,dp);
    int notrob = solve(nums,i+1,n,dp);
    return dp[i]=max(rob,notrob);

}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,n,dp);
        
    }
};