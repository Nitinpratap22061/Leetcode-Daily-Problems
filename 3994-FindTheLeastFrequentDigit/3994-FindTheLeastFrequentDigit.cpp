// Last updated: 10/5/2025, 8:48:15 AM
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int freq[10] = {0}; 
        string s = to_string(n);
        
        for (char c : s) {
            freq[c - '0']++;
        }

        int minFreq = INT_MAX;
        int ans = 0;

        for (int i = 0; i <= 9; i++) {
            if (freq[i] > 0 && freq[i] < minFreq) {
                minFreq = freq[i];
                ans = i;
            }
        }

        return ans;
    }
};
