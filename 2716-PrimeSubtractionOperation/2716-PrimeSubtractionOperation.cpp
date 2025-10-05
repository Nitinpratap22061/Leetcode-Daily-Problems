// Last updated: 10/5/2025, 8:51:25 AM
class Solution {
public:
     bool isprime[1000];
     void seive()
     {
        fill(isprime , isprime+1000 , true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2 ; i*i <1000 ; i++)
        {
            if(isprime[i])
            {
                for(int j=i*i ; j<1000 ; j+=i)
                {
                    isprime[j] =  false;
                }
            }
        }
     }
    bool primeSubOperation(vector<int>& nums) {
     int n = nums.size();
     seive();
     for(int i=n-2 ; i>=0 ; i--)
     {
        if(nums[i]<nums[i+1])
        {
            continue;
        }
        for(int p=2 ; p<nums[i] ; p++)
        {
            if(!isprime[p])
            {
                continue;
            }
            if(nums[i]-p < nums[i+1])
            {
                nums[i]-=p;
                break;
            }
        }
        if(nums[i]>=nums[i+1])
        {
            return false;
        }
     }  
     return true; 
    }
};
