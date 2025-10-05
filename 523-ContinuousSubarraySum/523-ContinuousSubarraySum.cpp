// Last updated: 10/5/2025, 8:58:45 AM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;  // Handle the case when the entire array is a multiple of k.

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            if (k != 0) {
                sum %= k;
            }

            if (remainderMap.find(sum) != remainderMap.end()) {
                if (i - remainderMap[sum] > 1) {
                    return true;
                }
            } else {
                remainderMap[sum] = i;
            }
        }

        return false;
    }
};
