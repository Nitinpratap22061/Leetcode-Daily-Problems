// Last updated: 10/5/2025, 8:48:06 AM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size() ; 
        
        vector<bool>inc(n,false) ; 
        vector<bool>dec(n,false) ; 
        vector<long long>pre(n ,0 ) ; 
        vector<long long> suff(n,0) ; 

        for(int i = 0 ; i<n ; i++)
        {
            if(i==0)
            {
                inc[i] = true ; 
                pre[i] = nums[i] ; 
            }
            else
            {
                if(nums[i-1]<nums[i]) // inc
                {
                  inc[i] = inc[i-1] ; 
                }
                pre[i] = (long long)(pre[i-1]+nums[i]);
            }
        } 

        for(int i = n-1 ; i>=0 ; i--)
        {
            if(i==n-1)
            {
                dec[i] = true ;
                suff[i] = nums[i];
            }
            else
            {
                if(nums[i+1]<nums[i])
                {
                    dec[i] = dec[i+1] ; 
                }
                suff[i] = (long long)(suff[i+1]+nums[i]) ; 
            }
        } 

        long long res =LLONG_MAX; 
        for(int i = 0 ; i<n-1 ; i++)
        {
            if(inc[i]&&dec[i+1])
            {
                res = min(res , (llabs(pre[i]-suff[i+1]))) ; 
            }
        }
        return res==LLONG_MAX ?-1:res ; 

    }
};