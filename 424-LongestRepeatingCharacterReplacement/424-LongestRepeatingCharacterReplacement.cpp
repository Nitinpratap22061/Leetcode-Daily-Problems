// Last updated: 10/5/2025, 8:59:04 AM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < n) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int windowSize = j - i + 1;

            if (windowSize - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
