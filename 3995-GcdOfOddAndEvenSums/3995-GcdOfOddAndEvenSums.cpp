// Last updated: 10/5/2025, 8:48:14 AM
class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int help = a % b;
        a = b;
        b = help;
    }
    return a;
}

    int gcdOfOddEvenSums(int n) {

        int oddsum = n*n ; 
        int evensum = n*(n+1) ; 
        return gcd(oddsum , evensum) ; 
        
    }
};