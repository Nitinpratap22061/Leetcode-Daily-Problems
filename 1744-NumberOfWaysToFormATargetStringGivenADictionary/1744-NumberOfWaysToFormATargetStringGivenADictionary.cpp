// Last updated: 10/5/2025, 8:54:39 AM
class Solution {
public:
  int t[1001][1001];
  const int mod = 1e9+7 ; 
    int n;
    int k;
    int solve(int i, int j, vector<vector<long long>>& freq, string& target) {
        if (i == n)
            return 1;
        if (j == k)
            return 0;
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
        int not_taken = solve(i, j + 1, freq, target)%mod;
        int taken =
            freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target)%mod;

            return t[i][j]=(taken+not_taken)%mod;
    }
    int numWays(vector<string>& words, string target) {
        n = target.size();
        k = words[0].size();
        vector<vector<long long>> freq(26, vector<long long>(k));
        for (int col = 0; col < k; col++) {
            for (string& word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }
        memset(t,-1,sizeof(t));

        return solve(0, 0, freq, target);
    }
};