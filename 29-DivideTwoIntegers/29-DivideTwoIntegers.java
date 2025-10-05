// Last updated: 10/5/2025, 9:02:35 AM
class Solution {
    public int divide(int dividend, int divisor) {
        // Handle special case where dividend is Integer.MIN_VALUE and divisor is -1
        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;

        return dividend / divisor;
    }
}