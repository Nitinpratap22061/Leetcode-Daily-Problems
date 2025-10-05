// Last updated: 10/5/2025, 9:02:20 AM
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        
        double result = 1.0;
        long long absN = abs(static_cast<long long>(n)); // Handle INT_MIN
        
        while (absN > 0) {
            if (absN % 2 == 1)
                result *= x;
            x *= x;
            absN /= 2;
        }
        
        return n < 0 ? 1.0 / result : result;
    }
};
