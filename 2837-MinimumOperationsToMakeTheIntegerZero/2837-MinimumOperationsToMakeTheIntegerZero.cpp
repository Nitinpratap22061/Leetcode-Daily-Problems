// Last updated: 10/5/2025, 8:51:16 AM
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int op = 1; op <= 60; op++) {
            long long target = 1LL * num1 - (1LL * op * num2);

            if (target < op) 
            {
                break;  
            }
            int ones = __builtin_popcountll(target);  

            if (ones <= op) {
                return op;
            }
        }
        return -1;
    }
};
