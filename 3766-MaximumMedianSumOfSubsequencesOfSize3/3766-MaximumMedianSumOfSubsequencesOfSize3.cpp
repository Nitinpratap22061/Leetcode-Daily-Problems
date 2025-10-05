// Last updated: 10/5/2025, 8:49:04 AM
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        long long sum = 0;

        while (left < right) {
            sum += nums[right - 1];
            left += 1;        
            right -= 2;       
        }

        return sum;
    }
};
