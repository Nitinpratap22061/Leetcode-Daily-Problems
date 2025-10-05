// Last updated: 10/5/2025, 8:55:24 AM
class Solution {
public:
    const int MOD = 1e9+7;
    int n;
    vector<int> dp;  

    int solve(int idx, string &s, int k) {
        if (idx >= n) return 1; 
        if (s[idx] == '0') return 0; 
        if (dp[idx] != -1) return dp[idx]; 

        long long ans = 0;
        long long num = 0;

        for (int l = idx; l < n; l++) {
            num = (num * 10) + (s[l] - '0'); 
            if (num > k) break; 
            
            ans = (ans + solve(l + 1, s, k)) % MOD; 
        }

        return dp[idx] = ans; 
    }

    int numberOfArrays(string s, int k) {
        n = s.length();
        dp.assign(n, -1); 
        return solve(0, s, k);
    }
};
