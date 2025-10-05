// Last updated: 10/5/2025, 8:51:09 AM
class Solution {
public:
    int find(vector<vector<int>>& offers, int x) {
        int l = 0;
        int r = offers.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (offers[mid][0] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int solve(vector<vector<int>>& offers, int idx, vector<int>& dp) {
        int n = offers.size();
        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int nextIdx = find(offers, offers[idx][1]);
        int take = offers[idx][2] + solve(offers, nextIdx, dp);
        int skip = solve(offers, idx + 1, dp);
        return dp[idx] = max(take, skip);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> dp(offers.size(), -1);
        return solve(offers, 0, dp);
    }
};