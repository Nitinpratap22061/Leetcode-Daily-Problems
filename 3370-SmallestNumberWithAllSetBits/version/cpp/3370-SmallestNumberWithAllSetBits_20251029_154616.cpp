// Last updated: 10/29/2025, 3:46:16 PM
class Solution {
public:
    long long smallestNumber(long long n) {
        long long x = 1;
        while (2*x + 1 < n)
            x = 2*x + 1;
        if (x < n)
            x = 2*x + 1;
        return x;
    }
};
