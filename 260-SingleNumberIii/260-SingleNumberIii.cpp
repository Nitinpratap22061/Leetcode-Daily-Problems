// Last updated: 10/5/2025, 8:59:58 AM
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;

        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i];  
        }

        unsigned int rightmostsetbit = (unsigned int)x & (-(unsigned int)x);


        int a = 0, b = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & rightmostsetbit)
                a ^= nums[i];  
            else
                b ^= nums[i];  
        }

        return {a, b};
    }
};
