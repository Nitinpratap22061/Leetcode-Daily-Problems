// Last updated: 10/5/2025, 8:54:24 AM
class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.size();
        int zeroCount = 0;
        int firstZero = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (firstZero == -1) firstZero = i;
                zeroCount++;
            }
        }

        
        if (zeroCount <= 1) return s;

        
        string result(n, '1');
        result[firstZero + zeroCount - 1] = '0';
        return result;
    }
};
