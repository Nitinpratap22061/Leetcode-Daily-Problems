// Last updated: 10/5/2025, 8:49:26 AM
class Solution {
public:
int n;
int t[101][101][101];
int solve(vector<int>& nums, int k, int op1, int op2 , int i)
{
    if(i>=n)
    {
        return 0 ; 
    }
    int res = INT_MAX;
    if(t[op1][op2][i]!=-1)
    {
        return t[op1][op2][i];
    }
    //apply all poss opern
    if(op1>0)
    {
        int newval = ceil(nums[i]/2.0);
        int first = newval + solve(nums , k , op1-1 , op2 , i+1);
        res = min(res , first);
    }
    if(op2>0 && nums[i]>=k)
    {
        int newval = nums[i]-k;
        int second = newval + solve(nums,k,op1,op2-1,i+1);
        res = min(res,second);

    }
    //both
    if(op1>0 && op2>0)
    {
        int newval = ceil(nums[i]/2.0);
        if(newval>=k)
        {
            newval = newval - k ;
            int third = newval + solve(nums , k, op1-1 ,op2-1 , i+1);
            res = min(res , third);
        }
        if(nums[i]>=k)
        {
            newval = nums[i]-k;
            newval = (newval+1)/2;
            int fourth = newval + solve(nums,k,op1-1,op2-1,i+1);
            res = min(res,fourth);
        }
        

    }
    //no opern applied
        res = min(res , nums[i]+solve(nums , k,op1,op2,i+1));

        return t[op1][op2][i] =  res;

}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
         n = nums.size() ; 
         memset(t,-1,sizeof(t));
        return solve(nums , k , op1 , op2 , 0);
        
    }
};