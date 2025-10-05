// Last updated: 10/5/2025, 8:55:05 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int zeroCount = 1;
        int ans = 0;

        while (j < n) {
            if (nums[j] == 0) {
                zeroCount--;
            }

            while (zeroCount < 0) {
                if (nums[i] == 0) {
                    zeroCount++;
                }
                i++;
            }

            
            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }
};
