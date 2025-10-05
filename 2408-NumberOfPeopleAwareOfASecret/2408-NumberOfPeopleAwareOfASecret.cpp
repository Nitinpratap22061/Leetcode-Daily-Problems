// Last updated: 10/5/2025, 8:52:26 AM
class Solution {
    const int MOD = 1e9 + 7;
    int forget, delay, n;
    vector<int> memo;

    int solve(int day) {
        if (day == 1) {
            return 1;
        }

        if (memo[day] != -1) return memo[day];

        int res = 0;
        for (int prev = day - forget + 1; prev <= day - delay; ++prev) {
            if (prev > 0) {
                res = (res + solve(prev)) % MOD;
            }
        }

        return memo[day] = res;
    }

public:
    int peopleAwareOfSecret(int n_, int delay_, int forget_) {
        n = n_;
        delay = delay_;
        forget = forget_;
        memo.assign(n + 1, -1);

        int total = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day > 0) {
                total = (total + solve(day)) % MOD;
            }
        }

        return total;
    }
};
