// Last updated: 10/5/2025, 8:48:01 AM
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

         dp[1] = costs[1] + 1; 

        for (int i = 2; i <= n; i++) {
            if (dp[i - 1] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - 1] + costs[i] + 1);
            }

            if (i - 2 >= 0 && dp[i - 2] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - 2] + costs[i] + 4);
            }

            if (i - 3 >= 0 && dp[i - 3] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - 3] + costs[i] + 9);
            }
        }

        return dp[n];
    }
};
