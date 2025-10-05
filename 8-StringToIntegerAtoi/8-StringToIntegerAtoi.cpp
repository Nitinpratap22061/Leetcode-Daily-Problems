// Last updated: 10/5/2025, 9:02:57 AM
class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();

        // Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check if the first non-space character is a sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process the digits and build the result
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        return result * sign;
    }
};
