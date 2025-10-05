// Last updated: 10/5/2025, 9:02:07 AM
#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int carry = 1;
        vector<int> ans;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int sum = nums[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
