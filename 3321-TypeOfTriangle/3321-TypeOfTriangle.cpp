// Last updated: 10/5/2025, 8:50:25 AM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]>nums[2] && nums[0]+nums[2]>nums[1] && nums[1]+nums[2]>nums[0])
        {
        if(nums[0]==nums[1] && nums[1]==nums[2] && nums[0]==nums[2])
        {
            return "equilateral" ; 
        }
         else if(nums[0]!=nums[1] && nums[1]!=nums[2] && nums[0]!=nums[2])
        {
            return "scalene" ; 
        }
       else if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2])
        {
            return "isosceles";
        }
        }
        return "none";

        
    }
};