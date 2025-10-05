// Last updated: 10/5/2025, 8:53:00 AM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int total_ones = accumulate(begin(nums) , end(nums) , 0); // jitne sum utne 1

        int i=0;
        int j=0;
        int currOnes=0;
        int maxcount=0;

        while(j<2*n)
        {
            if(nums[j%n]==1)
            {
                currOnes++;
            }
            if(j-i+1 > total_ones)
            {
               currOnes -=  nums[i%n];
               i++;
            }
            maxcount = max(maxcount,currOnes);
            j++;
        }
        return total_ones - maxcount;
        
    }
};