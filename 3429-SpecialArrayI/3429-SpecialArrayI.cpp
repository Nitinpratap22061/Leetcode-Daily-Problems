// Last updated: 10/5/2025, 8:50:08 AM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            int ans = nums[i] + nums[i+1];
            if(ans%2 == 0)
            {
                return false;
            }
        }
        return true;
    }
};