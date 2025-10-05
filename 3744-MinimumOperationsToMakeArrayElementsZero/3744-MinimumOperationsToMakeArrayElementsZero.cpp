// Last updated: 10/5/2025, 8:49:09 AM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long solve(int l, int r) {
        long long L = 1;
        long long S = 1;
        long long steps = 0;

        while (L <= r) {
            long long R = 4 * L - 1;
            long long start = std::max<long long>(L, (long long)l);
            long long end = std::min<long long>(R, (long long)r);

            if (start <= end) {
                steps += (end - start + 1) * S;
            }

            S += 1;
            L = L * 4;
        }

        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];

            long long steps = solve(l, r);
            res += (steps + 1) / 2;
        }
        return res;
    }
};
