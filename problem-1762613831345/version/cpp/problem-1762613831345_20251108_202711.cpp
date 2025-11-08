// Last updated: 11/8/2025, 8:27:11 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int i = 0 ;
        int j = 0 ;
        int n= nums.size();
        for(int i = 0 ; i<n ; i++)
            {
                if(nums[i]==target)
                {
                    nums[i] = 1 ; 
                }
                else
                {
                    nums[i] = -1 ; 
                }
            }
           int count = 0 ; 
      
        //jis subaaray ka sum +ve wahan majority ele == taeget count that 
        for(int i = 0 ; i<n ; i++)
            {
                int sum = 0 ; 
                int j = i ; 
                while(j<n)
                    {
                        sum+=nums[j] ; 
                        if(sum>0){
                            count++ ; 
                        }
                        j++ ; 
                    }
            }

        return count ;
    }
};