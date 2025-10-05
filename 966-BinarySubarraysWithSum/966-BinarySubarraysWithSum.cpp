// Last updated: 10/5/2025, 8:57:02 AM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size() ; 
        int i = 0 ; 
        int j = 0 ; 
        int sum = 0 ;
        int count = 0 ;
        int count_zero = 0 ;
        while(j<n)
        {
            sum+=nums[j];
            
            while(i<j && (nums[i]==0||sum>goal))
            {
                if(nums[i]==0)
                {
                    count_zero++;
                }
                else
                {
                    count_zero = 0 ;
                }
                sum-=nums[i];
                i++;
            }
            if(sum==goal)
            {
                count +=1+count_zero;
            }
            j++;

        }
        return count;
        
    }
};