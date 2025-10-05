// Last updated: 10/5/2025, 9:01:01 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;
        for (int bit = 0; bit <= 31; bit++) {
            int countZero = 0;
            int countOne = 0;

            int temp = 1 << bit;
            for (auto& num : nums) {
                if ((num & temp) == 0) {
                    countZero++;
                } else {
                    countOne++;
                }
            }
            if (countOne % 3 == 1) {
                res = res | temp;
            }
        }
        return res;
    }
};