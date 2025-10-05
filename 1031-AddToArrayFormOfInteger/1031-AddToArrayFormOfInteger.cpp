// Last updated: 10/5/2025, 8:56:46 AM
#include <vector>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
        int size = num.size();
        std::vector<int> result;

        for (int i = size - 1; i >= 0 || k > 0; i--) {
            if (i >= 0) {
                k += num[i];
            }
            result.push_back(k % 10);
            k /= 10;
        }

        // Reverse the result vector
        std::reverse(result.begin(), result.end());

        return result;
    }
};
