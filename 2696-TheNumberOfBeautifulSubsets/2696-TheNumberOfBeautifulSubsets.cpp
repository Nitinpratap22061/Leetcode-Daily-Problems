// Last updated: 10/5/2025, 8:51:30 AM
class Solution {
public:
      int res;
      int n;
      int K;
      void solve(vector<int>& nums , int idx ,  unordered_map<int,int>& mp )
      {
        n = nums.size();
        if(idx>=n)
        {
            res++;
            return;
        }
        //not take
        solve(nums , idx+1 , mp);

        //take
        if(!mp[nums[idx]-K] && !mp[nums[idx]+K])
        {
            mp[nums[idx]]++;
            solve(nums , idx+1 ,mp);
            mp[nums[idx]]--;
           
        }
      }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        res =0 ;
        K=k;
        solve(nums , 0 , mp);

        return res-1;
        
    }
};