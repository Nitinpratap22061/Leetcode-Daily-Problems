// Last updated: 10/5/2025, 8:49:57 AM
class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int even  = 0 ; 
        int odd = 0  ; 
        for(auto ele:nums)
        {
            if(ele%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }

        int alternate =1 ;
        int currParity = nums[0]%2;
        for(int i = 1 ; i<nums.size() ; i++)
        {
            int parity = nums[i]%2;
            if(parity!=currParity)
            {
               alternate++;
               currParity = parity ; 
            }
        }

        return max({even , odd,alternate});
        
    }
};