// Last updated: 10/5/2025, 8:59:00 AM
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                duplicates.push_back(idx + 1);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        // Reset the array
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = abs(nums[i]);
        }
        return duplicates;
    }
};
