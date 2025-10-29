// Last updated: 10/29/2025, 3:43:17 PM
class Solution {
public:
    long long smallestNumber(long long n) {
        long long x = 1;
        while (x < n) {
            x = x * 2 + 1;  
        }
        return x;
    }
};
