// Last updated: 11/15/2025, 10:45:42 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Count 1s
        int ones = 0;
        for (int x : nums) if (x == 1) ones++;

        // Case 1: already has 1s
        if (ones > 0) return n - ones;

        // Case 2: find smallest subarray with gcd 1
        int minL = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    minL = min(minL, j - i + 1);
                    break; // no need to expand further
                }
            }
        }

        // No subarray with gcd = 1 → impossible
        if (minL == INT_MAX) return -1;

        // Total operations = (minL - 1) + (n - 1)
        return n + minL - 2;
    }
};
