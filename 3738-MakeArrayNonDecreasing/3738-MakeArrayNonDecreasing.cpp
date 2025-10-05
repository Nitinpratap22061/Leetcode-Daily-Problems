// Last updated: 10/5/2025, 8:49:13 AM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int p = -1 ; 
    for(int i =0 ; i<n ; i++)
    {
        if(nums[i]>=p)
        {
            p = nums[i];
        }
        else
        {
           
                count++;
            
        }
    }
    return n-count;
        
    }
};