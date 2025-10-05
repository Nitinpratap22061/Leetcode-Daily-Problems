// Last updated: 10/5/2025, 9:01:22 AM
class Solution {
public:
    int n, m;
    unordered_map<string, int> memo;

    int solve(string &s, string &t, int i, int j) {
        if (j == m) return 1;  // matched full t
        if (i == n) return 0;  // s exhausted

        string key = to_string(i) + "|" + to_string(j);
        if (memo.count(key)) return memo[key];

        int ans = 0;
        if (s[i] == t[j])
            ans += solve(s, t, i + 1, j + 1); // take s[i]
        
        ans += solve(s, t, i + 1, j); // skip s[i]

        return memo[key] = ans;
    }

    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memo.clear();
        return solve(s, t, 0, 0);
    }
};
