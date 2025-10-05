// Last updated: 10/5/2025, 8:52:16 AM
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long op = 0;
        int prev = nums[n - 1];

       for(int j = n-2 ; j>=0 ; j--)
       {
        if(nums[j]<=nums[j+1])
        {
            continue;
        }
        int parts = nums[j]/nums[j+1];
        if(nums[j]%nums[j+1]!=0)
        {
            parts++;
        }
        op+=parts-1;
        nums[j]  = nums[j]/parts;
       }
       return op;
    }
};
