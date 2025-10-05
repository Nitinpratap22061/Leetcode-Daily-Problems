// Last updated: 10/5/2025, 8:50:28 AM
class Solution {
public:
    typedef long long LL;
    long long flowerGame(int n, int m) {
        LL evenN = n / 2;
        LL oddN = (n + 1) / 2;
        LL evenM = m / 2;
        LL oddM = (m + 1) / 2;

        return evenN * oddM + oddN * evenM;
    }
};
