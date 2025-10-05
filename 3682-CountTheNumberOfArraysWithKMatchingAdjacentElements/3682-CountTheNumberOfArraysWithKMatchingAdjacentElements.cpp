// Last updated: 10/5/2025, 8:49:22 AM
#define ll long long
class Solution {
public:
    int md = 1e9+7;

    // ✅ Recursive fast exponentiation
    int binpow(int a, int b) {
        if (b == 0) return 1;
        ll half = binpow(a, b / 2);
        ll result = (half * half) % md;
        if (b % 2 == 1) result = (result * a) % md;
        return result;
    }

    // ✅ Modular inverse using Fermat’s little theorem
    int mdinv(int res) {
        return binpow(res, md - 2);
    }

    // ✅ Factorial
    int fact(int num) {
        if (num == 0 || num == 1) return 1;
        int res = 1;
        for (int i = 2; i <= num; i++) {
            res = ((ll)res * i) % md;
        }
        return res % md;
    }

    // ✅ Inverse factorial using modular inverse
    int invfact(int num) {
        int fac = fact(num);
        int invfac = mdinv(fac);
        return invfac % md;
    }

    // ✅ Your original logic
    int countGoodArrays(int n, int m, int k) {
        int nCr = ((ll)fact(n - 1) * (((ll)invfact(k) * invfact(n - k - 1)) % md)) % md;
        int power = binpow(m - 1, n - k - 1);  // now using recursive fast expo
        return ((ll)nCr * (((ll)m * power) % md)) % md;
    }
};
