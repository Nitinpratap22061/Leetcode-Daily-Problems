// Last updated: 9/27/2025, 12:43:14 AM
#include <vector>
#include <algorithm>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += right - left;
                    right--;
                } else {
                    
                    left++;
                }
            }
        }

        return count;
    }
};
