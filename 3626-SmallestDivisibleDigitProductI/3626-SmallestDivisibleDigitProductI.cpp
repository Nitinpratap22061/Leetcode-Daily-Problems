// Last updated: 10/5/2025, 8:49:35 AM
class Solution {
public:
    int smallestNumber(int n, int t) {
        int flag = 0;
        for (int i = n; i <= 100; i++) {
            int target = i; 
            int product = 1;
            while (target > 0) {
                int digit = target % 10;
                product = product * digit;
                target = target / 10;
            }
            if (product % t == 0) {
                flag = i;
                break;
            }
        }
        return flag;
    }
};
