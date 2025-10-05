// Last updated: 10/5/2025, 8:56:38 AM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, i = 0, j = 0, zeros = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) zeros++;

            while (zeros > k) {
                if (nums[i] == 0) zeros--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
