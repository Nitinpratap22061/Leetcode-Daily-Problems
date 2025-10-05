// Last updated: 10/5/2025, 8:48:34 AM
class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long solve(vector<vector<int>>& waitCost, int m, int n, int i, int j, int time) {
        if(i == m - 1 && j == n - 1) {
            return 0;
        }

        if(dp[i][j][time % 2] != -1) return dp[i][j][time % 2];

        long long res = LLONG_MAX;

        if(time % 2 == 1) {
            if(i + 1 < m) {
                long long cost = (i + 2) * (j + 1);
                res = min(res, cost + solve(waitCost, m, n, i + 1, j, time + 1));
            }
            if(j + 1 < n) {
                long long cost = (i + 1) * (j + 2);
                res = min(res, cost + solve(waitCost, m, n, i, j + 1, time + 1));
            }
        } else {
            res = waitCost[i][j] + solve(waitCost, m, n, i, j, time + 1);
        }

        return dp[i][j][time % 2] = res;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        dp = vector<vector<vector<long long>>>(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return (0 + 1) * (0 + 1) + solve(waitCost, m, n, 0, 0, 1);
    }
};
