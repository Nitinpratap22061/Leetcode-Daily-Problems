// Last updated: 10/5/2025, 9:01:54 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2; 

        while (i < nums.size()) {
           
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                nums.erase(nums.begin() + i);
               
            } else {
                i++;
            }
        }

        return nums.size();
    }
};
