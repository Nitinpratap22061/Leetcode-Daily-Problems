// Last updated: 10/5/2025, 9:00:20 AM
class Solution {
public:
    int t[101];
 
 int solve(vector<int>& nums,int i , int n)
 {
    if(i>n)
    {
        return 0;
    }
    if(t[i]!=-1)
    {
        return t[i];
    }
    int steal = nums[i] + solve(nums,i+2,n);
    int skip = solve(nums,i+1,n);
    return t[i] = max(steal,skip);
 }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        int i=0;
        memset(t,-1,sizeof(t));
        int skip_first = solve(nums,i,n-2);
        memset(t,-1,sizeof(t));
        int take_first = solve(nums,i+1,n-1);
        return max(skip_first,take_first);


        
    }
};