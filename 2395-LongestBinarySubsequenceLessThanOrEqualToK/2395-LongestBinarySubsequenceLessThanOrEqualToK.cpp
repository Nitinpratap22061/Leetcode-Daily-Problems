// Last updated: 10/5/2025, 8:52:30 AM
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long val = 0;
        long long pow2 = 1;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')  count++;       
            else {
                if (val + pow2 <= k) {
                    val += pow2;
                    count++;
                }
            }
            if (pow2 <= k) pow2 = pow2 * 2;     
        }
        return count;
    }
};