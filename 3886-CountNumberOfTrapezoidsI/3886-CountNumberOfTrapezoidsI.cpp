// Last updated: 10/5/2025, 8:48:41 AM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> y_count;

        for (auto& p : points) {
            y_count[p[1]]++;
        }

        // Step 2: For each y with at least 2 points, calculate combinations C(n, 2)
        vector<long long> combos;
        for (auto& [y, cnt] : y_count) {
            if (cnt >= 2) {
                combos.push_back(1LL * cnt * (cnt - 1) / 2);
            }
        }

        long long res = 0;
        long long prefix_sum = 0;
        for (long long c : combos) {
            res = (res + c * prefix_sum % MOD) % MOD;
            prefix_sum = (prefix_sum + c) % MOD;
        }

        return res;
    }
};
