// Last updated: 10/5/2025, 8:50:57 AM
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        
        // dp[i][j] = max number of elements picked to get sum j using first i elements
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                if (dp[i][sum] == -1) continue;

                
                dp[i + 1][sum] = max(dp[i + 1][sum], dp[i][sum]);

                if (sum + nums[i] <= target) {
                    dp[i + 1][sum + nums[i]] = max(dp[i + 1][sum + nums[i]], dp[i][sum] + 1);
                }
            }
        }

        return dp[n][target];
    }
};
