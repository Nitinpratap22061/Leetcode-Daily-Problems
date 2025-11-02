// Last updated: 11/2/2025, 2:26:11 PM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size() ; 
        int i = 0 ; 
        int j = 0 ; 
         int sum = 0 ; 
         int mini = INT_MAX;
        while(j<n)
        {
           sum+=nums[j];

           while(sum>=target)
           {
              int ws = j-i+1 ; 
              mini = min(mini,ws);
               sum-=nums[i];
               i++;
           }
           j++;
        }
        return mini==INT_MAX?0:mini;
        
    }
};