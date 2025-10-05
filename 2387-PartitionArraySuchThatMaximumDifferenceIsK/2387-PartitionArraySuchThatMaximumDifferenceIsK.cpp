// Last updated: 10/5/2025, 8:52:31 AM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size() ; 
        int count = 1 ; 
        int minval = nums[0];

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i]-minval>k)
            {
                count++;
                minval = nums[i];
            }
        }
        return count ; 
        
    }
};