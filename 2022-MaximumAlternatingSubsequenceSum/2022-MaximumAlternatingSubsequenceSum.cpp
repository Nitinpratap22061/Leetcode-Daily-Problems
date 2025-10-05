// Last updated: 10/5/2025, 8:53:47 AM
class Solution {
public:
   int n;
   typedef long long ll;
   ll t[100001][2];
   ll solve(vector<int>& nums , int idx , bool isEven)
   {
        n= nums.size();
            if(idx>=n)
            {
               return 0;
            }
            if(t[idx][isEven]!=-1)
            {
                return t[idx][isEven];
            }

       ll skip= solve(nums,idx+1,isEven);
        //take 
        ll val = nums[idx];
        if(!isEven)
        {
            val = -val;
        }
        ll take = val + solve(nums,idx+1,!isEven);
        return t[idx][isEven]=max(take,skip);

   }
    long long maxAlternatingSum(vector<int>& nums) {
       bool isEven =true;
       memset(t,-1,sizeof(t));
        return solve(nums,0,isEven);
    }
};