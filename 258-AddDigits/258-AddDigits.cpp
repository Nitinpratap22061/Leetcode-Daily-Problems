// Last updated: 10/5/2025, 9:00:00 AM
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        } else if (num % 9 == 0) {
            return 9;
        } else {
            return num % 9;
        }
    }
};
