// Last updated: 10/5/2025, 9:01:02 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            result=result^nums[i];
        }
        return result;
        
    }
};